//
// Created by hid3h on 24.06.2025.
//

#include "TranslateManager.hpp"

namespace core {
    TranslateManager::TranslateManager(std::string language) {
        this->currentLanguage = std::move(language);
    }

    TranslateManager::~TranslateManager() = default;

    void TranslateManager::loadLocalizations(nlohmann::json translateJson) {
        if (!translateJson.contains(this->currentLanguage))
            throw std::runtime_error("Not find language " + this->currentLanguage + '.');

        this->translate_list = translateJson[this->currentLanguage];
        if (!localization_map.empty()) this->localization_map.clear();
        for (const auto& [key, value] : this->translate_list.items())
            this->localization_map[key] = value.get<std::string>();
    }

    const std::map<std::string, std::string> &TranslateManager::dict() const {
        return localization_map;
    }

    std::string TranslateManager::translate(const std::string &key,
                                            const std::unordered_map<std::string, std::string>& placeholders) {
        auto it = localization_map.find(key);
        if (it == localization_map.end()) return "[[" + key + "]]";

        std::string translate = it->second;
        if (!placeholders.empty()) {
            for (const auto &[k, v]: placeholders) {
                std::string placeholder = "{" + k + "}";
                size_t pos;
                while ((pos = translate.find(placeholder)) != std::string::npos) {
                    translate.replace(pos, placeholder.length(), v);
                }
            }
        }
        return translate;
    }
} // core