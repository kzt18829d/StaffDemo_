//
// Created by hid3h on 23.06.2025.
//

#include "../include/AppSettings.hpp"

namespace core {
    AppSettings::AppSettings() {
#ifndef NDEBUG
        LocalizationDirectory   = std::filesystem::current_path()/"langs.json";
        ThemeDirectory          = std::filesystem::current_path()/"themes.json";
        StaffDirectory          = std::filesystem::current_path()/"staff.csv";
        LogDirectory            = std::filesystem::current_path()/"log.txt";

        currentLanguage         = "en";

#else
        LocalizationDirectory   = std::filesystem::current_path()/"langs.json";
        ThemeDirectory          = std::filesystem::current_path()/"themes.json";
        StaffDirectory          = std::filesystem::current_path()/"staff.csv";
        LogDirectory            = std::filesystem::current_path()/"log.txt";

        currentLanguage         = "en";
#endif

        themeManager            = std::make_unique<ThemeManager>();
        translateManager        = std::make_unique<TranslateManager>(currentLanguage);

    }

    std::filesystem::path AppSettings::getLocalizationDirectory() const {
        return LocalizationDirectory;
    }

    std::filesystem::path AppSettings::getThemeDirectory() const {
        return ThemeDirectory;
    }

    std::filesystem::path AppSettings::getStaffDirectory() const {
        return StaffDirectory;
    }

    std::filesystem::path AppSettings::getLogDirectory() const {
        return LogDirectory;
    }

    std::size_t AppSettings::getScreenWidth() const {
        return ScreenWidth;
    }

    std::size_t AppSettings::getScreenHeight() const {
        return ScreenHeight;
    }

    std::string AppSettings::getCurrentLanguage() const {
        return currentLanguage;
    }

    void AppSettings::setBaseWidthHeight() {
        ScreenWidth = 120;
        ScreenHeight = 30;
    }

    void AppSettings::setScreenWidth(std::size_t Width) {
        ScreenWidth = Width;
    }

    void AppSettings::setScreenHeight(std::size_t Height) {
        ScreenHeight = Height;
    }

} // core