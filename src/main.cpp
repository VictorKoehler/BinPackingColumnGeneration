#include <iostream>
#include "BinPacking.hpp"
#include "TimePoint.hpp"

int main(int argc, const char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " instance_path\n";
        exit(1);
    }
    auto instances = BinPackingData::parse_file(std::string(argv[1]));
    for (const auto& inst : instances) {
        TimePoint tp;
        auto s = solve_by_kantorovitch(inst);
        std::cout << "Execution took " << tp.diff_seconds() << " seconds\n";
        s.print();
        std::cout << "SANITY CHECK " << s.sanity_check() << "\n";
        std::cout << "SOLUTION COST: " << s.get_needed_bins() << "\n\n\n";
    }
    return 0;
}
