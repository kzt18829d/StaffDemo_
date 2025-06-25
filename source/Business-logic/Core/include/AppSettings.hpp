#ifndef STAFFDEMO_REFACTOR_APPSETTINGS_HPP
#define STAFFDEMO_REFACTOR_APPSETTINGS_HPP
#include <string>
#include <filesystem>
#include <memory>
#include "ThemeManager.hpp"
#include "TranslateManager.hpp"

///@namespace Core
///@brief Пространство имён главных компонентов программы
namespace core {

    ///@class AppSettings
    ///@brief Класс общих настроек приложения
    ///@details Класс общих настроек приложения, содержащий в себе данные путей, размеры окна,
    /// методы для их получения и изменения.
    /// Так же хранит в себе провайдер тем и репозитории.
    ///@addtogroup Core
    class AppSettings {
    private:
        std::filesystem::path LocalizationDirectory;
        std::filesystem::path ThemeDirectory;
        std::filesystem::path StaffDirectory;
        std::filesystem::path LogDirectory;

        std::size_t ScreenWidth {120};
        std::size_t ScreenHeight{30};

        std::string currentLanguage;
    public:

        AppSettings();

        std::filesystem::path getLocalizationDirectory() const;
        std::filesystem::path getThemeDirectory() const;
        std::filesystem::path getStaffDirectory() const;
        std::filesystem::path getLogDirectory() const;

        std::size_t getScreenWidth() const;
        std::size_t getScreenHeight() const;

        std::string getCurrentLanguage() const;

        void setBaseWidthHeight();
        void setScreenWidth(std::size_t Width);
        void setScreenHeight(std::size_t Height);

        std::unique_ptr<ThemeManager> themeManager;
        std::unique_ptr<TranslateManager> translateManager;
    };

} // core

#endif //STAFFDEMO_REFACTOR_APPSETTINGS_HPP
