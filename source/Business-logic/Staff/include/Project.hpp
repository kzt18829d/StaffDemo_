#ifndef STAFFDEMO_REFACTOR_PROJECT_HPP
#define STAFFDEMO_REFACTOR_PROJECT_HPP
#include <string>
#include <vector>
#include <memory>
//#include "IEngineer.hpp"

namespace staff {

    class IEngineer;

    ///@brief Класс проекта
    ///@details Хранит информацию о проекте и указатель на сотрудников, входящих в проект
    ///@param [in] name Название проекта
    ///@param [in] budget Бюджет проекта
    ///@param members Вектор сотрудников, участвующих в проекте. Не принимается конструктором.
    ///@ingroup Staff
    class Project : public std::enable_shared_from_this<Project> {
    private:
        std::string name;
        unsigned totalBudget;
        std::vector<std::weak_ptr<IEngineer>> members;

    public:
        ///@param name Имя проекта
        ///@param budget Бюджет проекта
        explicit Project(std::string  name, unsigned int budget=0);

        std::string getProjectName() const;
        unsigned getTotalBudget() const;

        std::vector<std::weak_ptr<IEngineer>> getAllMemebers() const;

        bool addMember(std::shared_ptr<IEngineer> member);
        bool removeMember(std::shared_ptr<IEngineer> member);

        bool operator==(const Project& other) const;
        bool operator!=(const Project& other) const;
        bool operator<(const Project& other) const;
        bool operator>(const Project& other) const;
    };

} // staff

#endif //STAFFDEMO_REFACTOR_PROJECT_HPP
