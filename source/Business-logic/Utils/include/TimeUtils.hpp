//
// Created by hid3h on 24.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_TIMEUTILS_HPP
#define STAFFDEMO_REFACTOR_TIMEUTILS_HPP
#include <string>

namespace utils {

    ///@brief Функция-TimeStamp
    ///@details Используется для получения текущей даты-времени для создаваемых файлов, если таковыми требуется
    ///@addtogroup Utils
    class TimeStamp {
    public:
        ///@brief возвращает текущее время
        ///@return string
        std::string getTime() const;
    };

} // utils

#endif //STAFFDEMO_REFACTOR_TIMEUTILS_HPP
