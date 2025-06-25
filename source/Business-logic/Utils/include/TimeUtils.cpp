#include "TimeUtils.hpp"
#include <ctime>
#include <algorithm>

namespace utils {
    std::string TimeStamp::getTime() const {
        const time_t now = time(nullptr);
        std::string time_str = ctime(&now);

        if (!time_str.empty() && time_str.back() == '\n') {
            time_str.pop_back();
        }

        std::replace(time_str.begin(), time_str.end(), ' ', '_');
        std::replace(time_str.begin(), time_str.end(), ':', '-');

        return time_str;
    }
} // utils