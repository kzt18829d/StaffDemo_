#ifndef STAFFDEMO_REFACTOR_THEME_HPP
#define STAFFDEMO_REFACTOR_THEME_HPP
#include <string>
#include "ThemeColor.hpp"
#include "ftxui/screen/color.hpp"

//#define TEXT_BASE "text_base"
//#define TEXT_PRIMARY "text_primary"
//#define TEXT_SECONDARY "text_secondary"
//#define TEXT_ERROR "text_error"
//#define TEXT_SUCCESS "text_success"
//#define TEXT_WARNING "text_warning"
//#define TEXT_INFO "text_info"
//#define TEXT_ACCENT "text_accent"
//#define BG_BASE "bg_base"
//#define BG_PRIMARY "bg_primary"
//#define BG_SECONDARY "bg_secondary"
//#define BG_SELECTED "bg_selected"
//#define BG_ACTIVE "bg_active"
//#define BORDER_WINDOW "border_window"
//#define BORDER_PRIMARY "border_primary"
//#define BORDER_FOCUSED "border_focused"
//#define BUTTON_STYLE "button_style"
//#define BUTTON_FOCUSED "button_focused"
//#define TEXT_WINDOW_HEADER "text_window_header"
//#define BORDER_WINDOW_HEADER "border_window_header"

namespace theme {

    ///@class Theme
    ///@brief Базовая единица цветовой схемы
    ///@details Структура, хранящая в себе информацию о цветах для передачи
    /// их компонентам и элементам ftxui::Component & ftxui::Element.
    ///@see ThemeColor
    ///@addtogroup Theme
    struct Theme {
        std::string name = "Default";
        // Type       Name                          Color                       palette
        ThemeColor text_base                = ftxui::Color::White;             // 15
        ThemeColor text_primary             = ftxui::Color::GrayLight;         // 7
        ThemeColor text_secondary           = ftxui::Color::GrayDark;          // 8
        ThemeColor text_error               = ftxui::Color::RedLight;          // 9
        ThemeColor text_success             = ftxui::Color::GreenLight;        // 10
        ThemeColor text_warning             = ftxui::Color::YellowLight;       // 11
        ThemeColor text_info                = ftxui::Color::BlueLight;         // 12
        ThemeColor text_accent              = ftxui::Color::Orange1;           // 214

        ThemeColor bg_base                  = ftxui::Color::Black;             // 0
        ThemeColor bg_primary               = ftxui::Color::Black;             // -1
        ThemeColor bg_secondary             = ftxui::Color::GrayDark;          // 8
        ThemeColor bg_selected              = ftxui::Color::Blue;              // 4
        ThemeColor bg_active                = ftxui::Color::DarkBlue;          // 18

        ThemeColor border_window            = ftxui::Color::White;             // 15
        ThemeColor border_primary           = ftxui::Color::GrayLight;         // 7
        ThemeColor border_focused           = ftxui::Color::Blue;              // 4

        ThemeColor text_window_header       = ftxui::Color::White;             // 15
        ThemeColor border_window_header     = ftxui::Color::White;             // 15

        bool operator==(const Theme& other) const { return this->name == other.name;}
        bool operator!=(const Theme& other) const { return !operator==(other); }
        bool empty() const { return this->name.empty(); }
    };
}
#endif //STAFFDEMO_REFACTOR_THEME_HPP
