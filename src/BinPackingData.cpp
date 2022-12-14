#include <fstream>
#include "BinPackingData.hpp"

void check_for_file_end(std::istream& input) {
    if (input.fail()) throw std::runtime_error("Stream has failed at some point");
    std::string line;
    while (std::getline(input, line)) {
        if (line.find_first_not_of("\t\n\r\t\f\v\0 ") != line.npos) throw std::runtime_error("Stream has not finished yet!: '" + line + "'");
    }
}

bool ends_with_lower(const std::string& s, const std::string& end) {
    auto path = s;
    std::transform(path.begin(), path.end(), path.begin(), [](unsigned char c){ return std::tolower(c); });
    return path.ends_with(end);
}

BinPackingData::BinPackingData(const std::string& file_path) : BinPackingData() {
    std::ifstream inp(file_path);
    if (ends_with_lower(file_path, "bpp")) parse_bpp(inp);
    else parse_txt(inp);
    check_for_file_end(inp);
}

void parse_weights(std::istream& input, std::vector<double>& weights, int n) {
    weights.clear();
    weights.reserve(n);
    while (n--) {
        double b;
        input >> b;
        weights.push_back(b);
    }
}

void BinPackingData::parse_txt(std::istream& input) {
    int n;
    double b;
    input >> name >> c >> n >> b;
    parse_weights(input, weights, n);
}

void BinPackingData::parse_bpp(std::istream& input) {
    int n;
    input >> n >> c;
    parse_weights(input, weights, n);
}

std::vector<BinPackingData> BinPackingData::parse_file(const std::string& file_path) {
    std::vector<BinPackingData> group;
    std::ifstream inp(file_path);
    bool is_bpp = ends_with_lower(file_path, "bpp");
    int num;
    if (is_bpp) num = 1;
    else inp >> num;
    while (num--) {
        if (is_bpp) group.emplace_back().parse_bpp(inp);
        else group.emplace_back().parse_txt(inp);
    }
    check_for_file_end(inp);
    return group;
}
