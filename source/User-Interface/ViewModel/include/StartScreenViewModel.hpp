//
// Created by hid3h on 25.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_STARTSCREENVIEWMODEL_HPP
#define STAFFDEMO_REFACTOR_STARTSCREENVIEWMODEL_HPP
#include "BasicViewModel.hpp"
#include "../../../Business-logic/Core/include/ScreenEnum.hpp"
#include <string>

namespace viewModel {

    ///@class StartScreenViewModel
    ///@brief Модель представления окна загрузки
    ///@see BasicViewModel
    ///@addtogroup ViewModel
    class StartScreenViewModel : public BasicViewModel {
    public:
        using Message = std::string;
        using Text = std::string;
    private:
        Message statusMessage;
        Text StaffDirectory;

        bool* createNewRepository = new bool{false};

    public:

        explicit StartScreenViewModel(std::shared_ptr<core::AppSettings> sharedPtr);
        ~StartScreenViewModel();

        std::string getTranslate(const std::string& key, const std::unordered_map<std::string, std::string>& placeholder={}) const override;
        theme::Theme& getTheme() const override;
        Message getStatusMessage() const;
        Text getStaffDirectory() const;
        bool* getCreateNewRepository();

        void setStatusMessage(Message msg);

        void useDefaultSettings();

        boost::signals2::signal<void(ScreenType nextScreen)> navigateToNextScreenSignal;
        boost::signals2::signal<void(Message&)> changeStatusMessageSignal;
    };

} // viewModel

#endif //STAFFDEMO_REFACTOR_STARTSCREENVIEWMODEL_HPP
