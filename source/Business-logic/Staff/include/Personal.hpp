//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_PERSONAL_HPP
#define STAFFDEMO_REFACTOR_PERSONAL_HPP
#include "IPersonal.hpp"
namespace staff {

    ///@brief Класс должности Cleaner
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@TPositon cleaner
    ///@see IPersonal
    ///@ingroup Staff
    class Cleaner : public IPersonal {
    public:
        Cleaner(std::string id_, std::string name_, std::string position_, int salary_);
        ~Cleaner() override = default;
    };

    ///@brief Класс должности Driver
    ///@param [in] name Имя единицы персонала
    ///@param [in] position Занимаемая должность
    ///@param [in] id Идентификатор единицы персонала, уникальное значение (16 знаков, 0-9 & a-z & A-Z)
    ///@param [in] salary Почасовая ставка
    ///@param [in] nBonus бонус за ночные смены
    ///@TPositon driver
    ///@see IPersonal
    ///@ingroup Staff
    class Driver : public IPersonal {
    private:
        int nightBonus;
    public:
        Driver(std::string id_, std::string name_, std::string position_, int salary_, int nBonus);
        ~Driver() override = default;
        int calcBonus() override;

        int getBonus() const;
        bool setBonus(int newBonus);
    };

} // staff

#endif //STAFFDEMO_REFACTOR_PERSONAL_HPP
