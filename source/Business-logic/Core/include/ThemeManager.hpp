//
// Created by hid3h on 25.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_THEMEMANAGER_HPP
#define STAFFDEMO_REFACTOR_THEMEMANAGER_HPP
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <boost/signals2.hpp>
#include "../../Theme/include/Theme.hpp"
namespace core {

    ///@class ThemeManager
    ///@brief Класс управления цветовыми схемами
    ///@see Theme
    ///@addtogroup Core
    ///@addtogroup Theme
    class ThemeManager {
    private:
        std::map<std::string, theme::Theme> theme_map;
        std::unique_ptr<theme::Theme> currentTheme = nullptr;

    public:
        ThemeManager();
        ~ThemeManager();

        ThemeManager(const ThemeManager&) = delete;
        ThemeManager(ThemeManager&&) = delete;
        ThemeManager& operator=(const ThemeManager&) = delete;
        ThemeManager& operator=(ThemeManager&&) = delete;

        bool setTheme(const std::string& themeName);
        theme::Theme& getTheme() const;
        const std::vector<std::string> getThemesNamesList() const;
        std::vector<theme::Theme> getThemesList() const;
        bool addTheme(theme::Theme& theme);

        boost::signals2::signal<void()> themeChangedSignal;
    };

} // core

#endif //STAFFDEMO_REFACTOR_THEMEMANAGER_HPP
