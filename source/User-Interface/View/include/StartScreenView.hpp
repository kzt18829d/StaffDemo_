//
// Created by hid3h on 25.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_STARTSCREENVIEW_HPP
#define STAFFDEMO_REFACTOR_STARTSCREENVIEW_HPP
#include "BasicView.hpp"
#include "StartScreenViewModel.hpp"


namespace view {

    ///@class StartScreenView
    ///@brief Представление окна загрузки
    ///@see BasicView
    ///@see StartScreenViewModel
    ///@addtogroup View
    class StartScreenView : public BasicView {
    private:
        using Text = std::string;

        std::shared_ptr<viewModel::StartScreenViewModel> viewModel;

        void updateTranslates();
        void updateStatusMessage(Text& msg);

        Text windowHeaderText;

        Text statusMessage;
        Text navigateToNextButtonText;
        Text createNewRepositoryText;

        Text staffDirectoryText;
        Text staffDirectoryPath;

        ftxui::Component createNewRepositoryCheckbox;
        ftxui::Component navigateToNextButton;

        ftxui::Component windowContainer;

    public:
        explicit StartScreenView(std::shared_ptr<viewModel::StartScreenViewModel> sharedPtr);
        ftxui::Element Render() override;
    };



} // view

#endif //STAFFDEMO_REFACTOR_STARTSCREENVIEW_HPP
