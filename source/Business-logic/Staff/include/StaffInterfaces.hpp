//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_STAFFINTERFACES_HPP
#define STAFFDEMO_REFACTOR_STAFFINTERFACES_HPP

namespace staff {
    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@see Personal
    struct WorkBaseTime {
        virtual int calcBase(int salary_, int worktime_) = 0;
        virtual int calcBonus() = 0;
        virtual ~WorkBaseTime() = default;
    };

    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@ingroup Interface
    struct ProjectBudget {
        virtual int calcBudgetPart(float part, int budget) = 0;
        virtual int calcProAdditions() = 0;
        virtual ~ProjectBudget() = default;
    };

    ///@brief Интерфейс для персонала
    ///@ingroup Interface
    ///@ingroup Interface
    struct Heading {
        virtual int calcHeads() = 0;
        virtual ~Heading() = default;
    };

}
#endif //STAFFDEMO_REFACTOR_STAFFINTERFACES_HPP
