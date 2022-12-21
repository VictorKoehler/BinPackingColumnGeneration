#include "BinPacking.hpp"
#include "cplex_util.h"

BinPackingSolution solve_by_kantorovitch(const BinPackingData& data, int time_limit, bool disable_optimizations) {
    IloEnv env;
    IloModel model(env);

    IloArray<IloBoolVarArray> x(env, data.N()); // 5.26
    for (int i = 0; i < data.N(); ++i) {
        IloBoolVarArray vetor(env, data.U());
        x[i] = vetor;
    }
    NAME_2D_VARS(data.N(), data.U(), x, "x(%d,%d)"); // Adicao da variável x ao modelo

    IloBoolVarArray y(env, data.U());
    NAME_VARS(data.U(), y, "y(%d)"); // Adicao da variável y ao modelo

    // Restrição Somatória de x = 1 para todo i em N
    for (int i = 0; i < data.N(); i++) {
        model.add(IloSum(x[i]) == 1);
    }

    // Restrição Somatória de w*x <= C*y para todo j em U
    for (int j = 0; j < data.U(); j++) {
        IloExpr s(env);
        for (int i = 0; i < data.N(); i++) s += data.get_weight(i)*x[i][j];
        model.add(s <= data.C()*y[j]);
        s.end();
    }

    model.add(IloMinimize(env, IloSum(y)));

    // Resolve
    IloCplex cplex(model);
    // CPLEX_MUTE(cplex);
    CPLEX_SOLVE_DEFAULT(cplex, time_limit, disable_optimizations);

    // Obtem solução
    IloNumArray Y_(env, data.U());
    cplex.getValues(Y_, y);

    IloArray<IloNumArray> X_(env, data.N());
    for (int i = 0; i < data.N(); ++i) {
        X_[i] = IloNumArray(env, data.U());
        cplex.getValues(X_[i], x[i]);
    }

    BinPackingSolution solution(&data);
    for (int j = 0; j < data.U(); j++) {
        if (Y_[j] < 0.5) continue;
        solution.bins.emplace_back();

        for (int i = 0; i < data.N(); i++) {
            if (X_[i][j] > 0.5) solution.bins.back().push_back(i);
        }
    }
    env.end();
    return solution;
}
