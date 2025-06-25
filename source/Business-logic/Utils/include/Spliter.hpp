#ifndef STAFFDEMO_REFACTOR_SPLITER_HPP
#define STAFFDEMO_REFACTOR_SPLITER_HPP
#include <vector>
#include <string>

///@namespace Utils
///@brief Пространство имён утилит
namespace utils {

    ///@class Spliter
    ///@brief обёртка функции разделения строки
    ///@addtogroup Utils
    class Spliter {
    public:
        ///@brief Функция для деления строки
        ///@param line Строка для разделения
        ///@param main_delim Вид разделителя
        ///@return std::vector
        std::vector<std::string> splitFileLine(std::string line, char main_delim=';');
    };

} // utils

#endif //STAFFDEMO_REFACTOR_SPLITER_HPP
