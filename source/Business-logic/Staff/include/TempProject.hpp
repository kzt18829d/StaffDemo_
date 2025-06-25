#ifndef STAFFDEMO_REFACTOR_TEMPPROJECT_HPP
#define STAFFDEMO_REFACTOR_TEMPPROJECT_HPP
#include <string>

namespace staff {

    ///@brief Шаблон временного хранилища единицы проекта
    ///@details Предназначен для временного хранения единицы проекта при передаче на чтение/запись в IStorageProvider.
    ///Хранит исключительно название проекта
    ///@param [in] name Название проекта
    ///@ingroup Staff
    struct TempProject {
        std::string name;
    };

}

#endif //STAFFDEMO_REFACTOR_TEMPPROJECT_HPP
