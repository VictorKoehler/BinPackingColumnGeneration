#include <vector>
#include <string>
#include <iostream>

struct BinPackingData {
    double c;
    std::vector<double> weights;
    std::string name;

    inline double C() const { return c; }
    inline int N() const { return int(weights.size()); }
    inline double get_weight(int i) const { return weights[i]; }
    virtual int U() const { return N(); }

    BinPackingData(int c, const std::vector<double>& weights, const std::string& name = "") : c(c), weights(weights), name(name) {}
    BinPackingData() : c(0), weights({}) {}
    BinPackingData(const std::string& file_path);

    void parse_txt(std::istream& input);
    void parse_bpp(std::istream& input);
    
    static std::vector<BinPackingData> parse_file(const std::string& file_path);
};

