#include "../include/BasicViewModel.hpp"

namespace viewModel {
    BasicViewModel::BasicViewModel(std::shared_ptr<core::AppSettings> sharedPtr) : appSettings(sharedPtr) {

    }

    BasicViewModel::~BasicViewModel() = default;

    theme::Theme &BasicViewModel::getTheme() const {
        return appSettings.lock()->themeManager->getTheme();
    }

    std::string BasicViewModel::getTranslate(const std::string &key, const std::unordered_map<std::string, std::string>& placeholder) const {
        if (!appSettings.expired()) return "[[" + key + "}}";
        return appSettings.lock()->translateManager->translate(key, placeholder);
    }
} // viewModel