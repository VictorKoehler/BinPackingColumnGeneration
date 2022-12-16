#include "BinPackingData.hpp"

struct BinPackingSolution {
    const BinPackingData* data;
    std::vector< std::vector<int> > bins;

    BinPackingSolution(const BinPackingData* data = NULL) : data(data) {}

    inline bool is_data_present() const { return data != NULL; }
    inline const BinPackingData* get_data() const { return data; }
    inline const std::vector< std::vector<int> >& get_bins() const { return bins; }
    inline int get_needed_bins() const { return int(bins.size()); }

    inline double get_bin_weight(int b) const {
        if (!is_data_present()) throw std::runtime_error("Data is not present");
        double s = 0;
        for (const auto i : bins[b]) s += data->get_weight(i);
        return s;
    }

    inline void print() const {
        if (is_data_present()) {
            std::cout << data->name << " (" << data->C() << ", " << data->N() << "): ";
        } else {
            std::cout << "*Data not present*: ";
        }
        std::cout << get_needed_bins() << "\n";
        for (size_t b = 0; b < bins.size(); b++) {
            std::cout << "[";
            for (const auto i : bins[b]) std::cout << " " << i;
            std::cout << " ] (" << (is_data_present() ? std::to_string(get_bin_weight(b)) : "*") << ")   ";
        }
        std::cout << "\n\n";
    }

    inline bool sanity_check() const {
        int n = is_data_present() ? data->N() : -1;
        if (n == -1) {
            std::cerr << "WARNING: Performing BinPackingSolution::sanity_check without cross checking data\n";
            for (const auto& b : bins) {
                for (const auto& i : b) {
                    n = std::max(i, n);
                }
            }
            n++;
        }

        std::vector<int> visited(n, 0);
        for (const auto& b : bins) {
            for (const auto& i : b) {
                visited[i]++;
            }
        }
        for (auto v : visited) {
            if (v != 1) return false;
        }
        return true;
    }
};
