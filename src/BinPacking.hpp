#include "BinPackingSolution.hpp"

BinPackingSolution solve_by_kantorovitch(const BinPackingData& data, int time_limit = 3600, bool disable_optimizations = true);
BinPackingSolution solve_by_gilmore_gomory(const BinPackingData& data, int time_limit = 3600, bool disable_optimizations = true);
