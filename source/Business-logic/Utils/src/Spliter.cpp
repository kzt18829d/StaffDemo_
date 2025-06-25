#include "../include/Spliter.hpp"
#include <sstream>

namespace utils {
    std::vector<std::string> Spliter::splitFileLine(std::string line, char main_delim) {
        if (line.empty()) return {};
        std::vector<std::string> temp;
        std::stringstream ss(std::move(line));
        std::string value;

        while (std::getline(ss, value, main_delim)) temp.push_back(value);
        return temp;
    }
} // utils