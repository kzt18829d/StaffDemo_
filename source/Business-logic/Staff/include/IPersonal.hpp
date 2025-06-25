//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_IPERSONAL_HPP
#define STAFFDEMO_REFACTOR_IPERSONAL_HPP
#include "IEmployee.hpp"
#include "StaffInterfaces.hpp"

namespace staff {

    ///@brief Шаблон для классов-наследников IPersonal
    ///@details Абстрактный класс, от которого наследуются большинство единиц персонала.
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@TPositon personal
    ///@see IEmployee
    ///@ingroup Staff
    class IPersonal : public IEmployee, public WorkBaseTime {
    protected:
        int salary;

    public:
        IPersonal(std::string id_, std::string name_, std::string position_, int salary_);
        virtual ~IPersonal() override = default;

        int calcBase(int salary_, int worktime_) override;
        int calcBonus() override;

        void calc() override;

        int getSalary() const;
        bool setSalary(int newSalary);

        std::string makeLineForFile(char delim, char subDelim = ',') override;

    };

} // staff

#endif //STAFFDEMO_REFACTOR_IPERSONAL_HPP
