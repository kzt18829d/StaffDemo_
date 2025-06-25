#ifndef STAFFDEMO_REFACTOR_THEMECOLOR_HPP
#define STAFFDEMO_REFACTOR_THEMECOLOR_HPP
#include <ftxui/screen/color.hpp>
#include <cstdint>

///@namespace Theme
///@brief Пространство имён цветовых структур и связанных элементов
namespace theme {

    ///@class ThemeColor
    ///@brief Структура единицы цвета
    ///@details Предназначена для решения конфликта между структурой цветов
    /// от ftxui::Color и хранением цветовых схем и цветов в частности.
    /// Поддерживает как Palette16/Palette256 цвета ftxui,
    /// так и ftxui::TrueColor (RGB) цвета
    ///@addtogroup Theme
    struct ThemeColor {

        ///@enum Type
        ///@brief Цветовые палитры, аналогичные ftxui::Color
        enum class Type {
            Default,
            Palette16,
            Palette256,
            RGB
        };

        Type type = Type::Default;
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
        uint8_t palette = 0;

        ///@brief Используется для ftxui::Color::Palette1
        ThemeColor() = default;

        ///@brief Используется для ftxui::Color::Palette16
        ///@param index Palette16 ftxui::Color
        ThemeColor(ftxui::Color::Palette16 index) : type(Type::Palette16), palette(static_cast<uint8_t>(index)) {}

        ///@brief Используется для ftxui::Color::Palette256
        ///@param index Palette256 ftxui::Color
        ThemeColor(ftxui::Color::Palette256 index) : type(Type::Palette256), palette(static_cast<uint8_t>(index)) {}

        ///@brief Используется для ftxui::Color::RGB
        ///@details Конструктор для стандартного RGB-цвета
        ///@param red_ RGB/Red
        ///@param green_ RGB/Green
        ///@param blue_ RGB/Blue
        ThemeColor(uint8_t red_, uint8_t green_, uint8_t blue_) : type(Type::RGB), red(red_), green(green_), blue(blue_) {}

        ///@details Возвращает цвет от ftxui::Color
        /// в зависимости от типа используемой цветовой палитры
        ///@return ftxui::Color
        operator ftxui::Color() const {
            switch (type) {
                case Type::Default : return ftxui::Color::Default;
                case Type::Palette16 : return ftxui::Color(ftxui::Color::Palette16(palette));
                case Type::Palette256 : return ftxui::Color(ftxui::Color::Palette256(palette));
                case Type::RGB : return ftxui::Color::RGB(red, green, blue);
                default: return ftxui::Color::Default;
            }
        }
    };
}
#endif //STAFFDEMO_REFACTOR_THEMECOLOR_HPP
