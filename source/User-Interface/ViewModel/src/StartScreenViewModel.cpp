#include "StartScreenViewModel.hpp"

namespace viewModel {
    StartScreenViewModel::StartScreenViewModel(std::shared_ptr<core::AppSettings> sharedPtr) : BasicViewModel(
            sharedPtr) {
        if (!appSettings.expired()) StaffDirectory = appSettings.lock()->getStaffDirectory().string();

    }

    StartScreenViewModel::Message StartScreenViewModel::getStatusMessage() const {
        return statusMessage;
    }

    StartScreenViewModel::Text StartScreenViewModel::getStaffDirectory() const {
        return StaffDirectory;
    }

    void StartScreenViewModel::setStatusMessage(StartScreenViewModel::Message msg) {
        statusMessage = std::move(msg);
    }

    void StartScreenViewModel::useDefaultSettings() {
        navigateToNextScreenSignal(ScreenType::LOAD_EMPLOYEE_SCREEN);
    }

    StartScreenViewModel::~StartScreenViewModel() {
        delete createNewRepository;
    }

    bool *StartScreenViewModel::getCreateNewRepository() {
        return createNewRepository;
    }

    std::string StartScreenViewModel::getTranslate(const std::string &key,
                                                   const std::unordered_map<std::string, std::string> &placeholder) const {
        return BasicViewModel::getTranslate(key, placeholder);
    }

    theme::Theme &StartScreenViewModel::getTheme() const {
        return BasicViewModel::getTheme();
    }
} // viewModel