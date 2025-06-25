//
// Created by hid3h on 25.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_TRANSLATESTORAGEPROVIDER_HPP
#define STAFFDEMO_REFACTOR_TRANSLATESTORAGEPROVIDER_HPP
#include <filesystem>
#include "../../Utils/include/json.hpp"

namespace fileManager {

    class TranslateStorageProvider {
    private:
        std::filesystem::path LocalizationJsonDirectory;
        nlohmann::json loadedLanguagePacks;

    public:
        explicit TranslateStorageProvider(std::filesystem::path filePath);
        ~TranslateStorageProvider();

        void loadFromJson();
        nlohmann::json getLanguagePacks();
    };

} // fileManager

#endif //STAFFDEMO_REFACTOR_TRANSLATESTORAGEPROVIDER_HPP
