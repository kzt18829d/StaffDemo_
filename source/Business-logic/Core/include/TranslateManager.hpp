//
// Created by hid3h on 24.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_TRANSLATEMANAGER_HPP
#define STAFFDEMO_REFACTOR_TRANSLATEMANAGER_HPP
#include <string>
#include <map>
#include "../../Utils/include/json.hpp"

namespace core {

    ///@brief Менеджер переводов
    ///@details Подгружает перевод фраз/слов из JSON для последующего отображения на экране
    ///@ingroup Core
    class TranslateManager {
    private:
        nlohmann::json translate_list;
        std::map<std::string, std::string> localization_map;
        std::string currentLanguage;

    public:
        TranslateManager(std::string language);
        ~TranslateManager();

        void loadLocalizations(nlohmann::json translateJson);

        const std::map<std::string, std::string>& dict() const;
        std::string translate(const std::string& key, const std::unordered_map<std::string, std::string>& placeholders = {});
    };



} // core

#endif //STAFFDEMO_REFACTOR_TRANSLATEMANAGER_HPP
