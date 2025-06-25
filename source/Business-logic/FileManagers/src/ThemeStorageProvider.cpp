//
// Created by hid3h on 24.06.2025.
//

#include "ThemeStorageProvider.hpp"
#include <fstream>

namespace fileManager {
    ThemeStorageProvider::ThemeStorageProvider() = default;


    std::vector<theme::Theme> ThemeStorageProvider::readThemes() const {
        if (!exists(themeFile)) return {};
        std::ifstream file(themeFile);
        if (!file.is_open()) throw std::runtime_error("Fail open themes file \'" + themeFile.string() + '\'');

        try {
            nlohmann::json themesJson;
            file >> themesJson;
            std::vector<theme::Theme> themesList;
            for (const auto& theme: themesJson.items()) {
                theme::Theme newTheme;
                // TODO сдедать чтение и запись

//                themesList.push_back(theme.value().get<theme::Theme>());
            }
            return themesList;
        } catch (const nlohmann::json::parse_error &parse_error) {
            throw std::runtime_error("Fail parsing themes.json: " + std::string(parse_error.what()));
        } catch (const std::exception &exception) {
            throw std::runtime_error("Standard Template Library error: " + std::string(exception.what()));
        }

    }

    void ThemeStorageProvider::saveThemes(std::vector<theme::Theme> &themes) {

    }
} // fileManager