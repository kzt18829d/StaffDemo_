#ifndef STAFFDEMO_REFACTOR_IEMPLOYEE_HPP
#define STAFFDEMO_REFACTOR_IEMPLOYEE_HPP
#include <string>

///@defgroup Staff Персонал

namespace staff {

    ///@brief Класс-интерфейс персонала
    ///@details Базовый абстрактный класс-интерфейс, от которого прочие классы персонала.
    ///Содержит общие параметры всех классов сотрудника
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@TPosition employee
    ///@ingroup Staff
    ///@ingroup Interface
    class IEmployee {
    protected:
        std::string id;
        std::string employeeName;
        std::string employeePosition;
        int workTime;
        int payment;

    public:
        IEmployee(std::string id_, std::string name_, std::string position_ );
        virtual ~IEmployee();

        virtual void calc() = 0;

        void setWorkTime(int workTime_);
        std::string getID() const;
        std::string getName() const;
        std::string getPosition() const;
        int getWorkTime() const;
        int getPayment() const;

        virtual std::string makeLineForFile(char delim, char subDelim=',') = 0;

        bool operator==(const IEmployee &other) const;
        bool operator!=(const IEmployee &other) const;

    };

} // staff

#endif //STAFFDEMO_REFACTOR_IEMPLOYEE_HPP
