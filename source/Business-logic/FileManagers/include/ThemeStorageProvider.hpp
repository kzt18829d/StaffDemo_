#ifndef STAFFDEMO_REFACTOR_THEMESTORAGEPROVIDER_HPP
#define STAFFDEMO_REFACTOR_THEMESTORAGEPROVIDER_HPP
#include "json.hpp"
#include <vector>
#include "filesystem"
#include "Theme.hpp"

///@namespace FileManager
///@brief Пространство имён взаимодействующих с файлами классов
namespace fileManager {

    ///@class ThemeStorageProvider
    ///@brief Посредник между файловой системой и ThemeManager.
    ///@details Предназначен для взаимодействия с файлами,
    /// непосредственно относящимися к цветовым схемам GUI/TUI
    ///@see Theme
    ///@see ThemeColor
    ///@see ThemeManager
    ///@addtogroup Provider
    ///@addtogroup Theme
    class ThemeStorageProvider {
    private:
        std::filesystem::path themeFile = std::filesystem::current_path()/"themes.json";

    public:
        ThemeStorageProvider();

        std::vector<theme::Theme> readThemes() const;
        void saveThemes(std::vector<theme::Theme>& themes);
    };



} // fileManager

#endif //STAFFDEMO_REFACTOR_THEMESTORAGEPROVIDER_HPP
