#include "TranslateStorageProvider.hpp"
#include <fstream>
#include <iostream>

namespace fileManager {
    TranslateStorageProvider::TranslateStorageProvider(std::filesystem::path filePath) {
        if (!is_regular_file(filePath)) throw std::runtime_error("Not valid lang file: \"" + filePath.string() + '\"');
        this->LocalizationJsonDirectory = std::move(filePath);
    }

    TranslateStorageProvider::~TranslateStorageProvider() = default;

    void TranslateStorageProvider::loadFromJson() {
        std::ifstream JSON(this->LocalizationJsonDirectory, std::ios::in);

        if (!JSON.is_open()) {
            std::cerr << "~~~~~~ ERROR. FAIL OPEN FILE " << this->LocalizationJsonDirectory.string() << "." << std::endl;
            return;
        }
        try {
            JSON >> this->loadedLanguagePacks;
        } catch (std::exception &ex) {
            throw std::runtime_error("Parsing Error: " + std::string(ex.what()));
        }
    }

    nlohmann::json TranslateStorageProvider::getLanguagePacks() {
        return this->loadedLanguagePacks;
    }
} // fileManager