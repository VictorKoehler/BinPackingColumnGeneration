#include <iostream>
#include "BinPacking.hpp"
#include "TimePoint.hpp"

int main(int argc, const char** argv) {
    if (argc != 3 || (argv[1][0] != 'k' && argv[1][0] != 'g')) {
        std::cout << "Usage: " << argv[0] << " [k]antorovitch|[g]ilmore_gomory instance_path\n";
        exit(1);
    }
    auto instances = BinPackingData::parse_file(std::string(argv[2]));
    for (const auto& inst : instances) {
        TimePoint tp;
        auto s = (argv[1][0] == 'k' ? solve_by_kantorovitch(inst, 600, false) : solve_by_gilmore_gomory(inst, 600, false));
        std::cout << "Execution took " << tp.diff_seconds() << " seconds\n";
        s.print();
        std::cout << "SANITY CHECK " << s.sanity_check() << "\n";
        std::cout << "SOLUTION COST: " << s.get_needed_bins() << "\n\n\n";
    }
    return 0;
}
