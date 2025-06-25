//
// Created by hid3h on 25.06.2025.
//

#include "ThemeManager.hpp"

namespace core {
    ThemeManager::ThemeManager() {
        theme_map["Default"] = theme::Theme();
        setTheme("Default");
//        currentTheme = std::make_unique<theme::Theme>(theme_map.at("Default"));
    }

    ThemeManager::~ThemeManager() = default;

    bool ThemeManager::setTheme(const std::string &themeName) {
        if (!theme_map.contains(themeName)) return false;
        currentTheme = std::make_unique<theme::Theme>(theme_map.at(themeName));
        return true;
    }

    theme::Theme &ThemeManager::getTheme() const {
        return *currentTheme;
    }

    const std::vector<std::string> ThemeManager::getThemesNamesList() const {
        std::vector<std::string> names;
        for (const auto& line: theme_map) names.push_back(line.first);
        return names;
    }

    std::vector<theme::Theme> ThemeManager::getThemesList() const {
        std::vector<theme::Theme> themes;
        for (const auto& theme: theme_map) themes.push_back(theme.second);
        return themes;
    }

    bool ThemeManager::addTheme(theme::Theme &theme) {
        if (theme_map.contains(theme.name)) return false;
        theme_map[theme.name] = std::move(theme);
        return true;
    }
} // core