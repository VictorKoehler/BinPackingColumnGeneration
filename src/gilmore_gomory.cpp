#include <unordered_map>
#include "BinPacking.hpp"
#include "cplex_util.h"

class KnapsackSolver {
    IloEnv& env;
    IloModel model;
    IloCplex cplex;
    IloBoolVarArray x;
    IloObjective obj;

    public:
    KnapsackSolver(IloEnv& env, const std::vector<double>& weights, double C, bool disable_optimizations = false)
                : env(env), model(env), cplex(model), x(env, weights.size()) {
        NAME_VARS(x.getSize(), x, "x(%d)"); // Adicao da variável x ao modelo
        IloExpr e(env);
        for (int i = 0; i < x.getSize(); i++) {
            e += weights[i]*x[i];
        }
        model.add(e <= C);
        CPLEX_MUTE(cplex);
        CPLEX_CONFIG(cplex, 3600, disable_optimizations);
    }

    double solve(const IloNumArray& pi, IloNumArray& new_cols) {
        IloExpr e(env);
        for (int i = 0; i < x.getSize(); i++) {
            e += pi[i]*x[i];
        }
        obj = IloMinimize(env, 1-e);
        model.add(obj);
        cplex.solve();
        double r = cplex.getBestObjValue();
        cplex.getValues(x, new_cols);
        model.remove(obj);
        obj.end();
        return r;
    }
};

BinPackingSolution solve_by_gilmore_gomory(const BinPackingData& data, int time_limit, bool disable_optimizations) {
    IloEnv env;
    IloModel model(env);

    IloNumVarArray lambda(env, data.N(), 0, 1);
    NAME_VARS(data.N(), lambda, "l(%d)"); // Adicao da variável lambda ao modelo

    IloRangeArray constraints(env);
    for (int i = 0; i < data.N(); i++) {
        constraints.add(lambda[i] == 1);
    }
    model.add(constraints);

    auto obj = IloAdd(model, IloMinimize(env, IloSum(lambda)));

    KnapsackSolver knapsack(env, data.get_weights(), data.C(), disable_optimizations);

    IloCplex cplex(model);
    CPLEX_MUTE(cplex);
    CPLEX_CONFIG(cplex, time_limit, disable_optimizations);

    char buffer[100];
    IloNumArray duals(env, data.N()), new_cols(env, data.N());
    int iter;
    for (iter = 1; iter < 0x3FFFFFFF; iter++) {
        cplex.solve();
        cplex.getDuals(duals, constraints);

        auto r = knapsack.solve(duals, new_cols);
        if (r >= -1e-12) {
            // std::cout << "r       : " << r << " " << data.C() << "\n";
            // std::cout << "duals   : " << duals << "\n";
            // std::cout << "new_cols: " << new_cols << "\n";
            // IloNumArray w(env), wd(env), lmbdv(env, lambda.getSize());
            // for (size_t i = 0; i < data.weights.size(); i++) {
            //     w.add(data.get_weight(i));
            //     wd.add(data.get_weight(i)*new_cols[i]);
            // }
            // std::cout << "w       : " << w << "\n";
            // std::cout << "wd      : " << wd << " => " << IloSum(wd) << "\n";
            // cplex.getValues(lmbdv, lambda);
            // std::cout << "lambda  : " << lmbdv << "\n";
            break;
        }

        if (iter % 10 == 0) std::cout << "Iteration " << iter << ": obj=" << cplex.getObjValue() << "  r=" << r << "\n";

        IloNumVar var(obj(1) + constraints(new_cols), 0, 1);
        sprintf(buffer, "lp(%d)", iter);
        var.setName(buffer);
        lambda.add(var);
        model.add(lambda[lambda.getSize()-1]);
    }
    std::cout << "Problem ran for " << iter << " iterations\n";
    model.add(IloConversion(env, lambda, ILOINT));
    cplex.solve();

    std::unordered_map< std::string, std::vector<int> > vars_bins;
    for (int i = 0; i < constraints.getSize(); ++i) {
        IloExpr rngexpr = constraints[i].getExpr();
        for (IloExpr::LinearIterator rngit(rngexpr.getLinearIterator()); rngit.ok(); ++rngit) {
            if (rngit.getCoef() <= 0.5) continue;
            const auto n = rngit.getVar().getName();
            vars_bins.try_emplace(n);
            vars_bins[n].push_back(i);
        }
    }

    BinPackingSolution sol(&data);
    IloNumArray lambda_values(env, lambda.getSize());
    cplex.getValues(lambda, lambda_values);
    for (int i = 0; i < lambda_values.getSize(); i++) {
        if (lambda_values[i] > 0.5) {
            const auto& vb = vars_bins[lambda[i].getName()];
            sol.bins.emplace_back(vb);
        }
    }
    return sol;
}