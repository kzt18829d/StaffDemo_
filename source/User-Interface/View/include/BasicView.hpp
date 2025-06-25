#ifndef STAFFDEMO_REFACTOR_BASICVIEW_HPP
#define STAFFDEMO_REFACTOR_BASICVIEW_HPP
#include <ftxui/component/component_base.hpp>
#include "BasicViewModel.hpp"
#include <memory>

///@namespace View
///@brief Пространство имён представлений
namespace view {

    ///@class BasicView
    ///@brief Базовый класс представления
    ///@addtogroup View
    class BasicView : public ftxui::ComponentBase {
    public:
//        virtual ftxui::Element Render() = 0;
    };

} // view

#endif //STAFFDEMO_REFACTOR_BASICVIEW_HPP
