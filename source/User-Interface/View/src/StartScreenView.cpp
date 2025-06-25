//
// Created by hid3h on 25.06.2025.
//

#include "StartScreenView.hpp"
#include <ftxui/component/component.hpp>
#include <utility>
#include <fmt/core.h>
namespace view {
    void StartScreenView::updateTranslates() {
        windowHeaderText = viewModel->getTranslate("TITLE_1F");

        navigateToNextButtonText = viewModel->getTranslate("VIEW_StartScreen_navigateToNextButton");
        createNewRepositoryText = viewModel->getTranslate("VIEW_StartScreen_createNewRepositoryText");

        staffDirectoryText = viewModel->getTranslate("VIEW_GLOBAL_staffDirectoryText");

    }

    void StartScreenView::updateStatusMessage(StartScreenView::Text &msg) {

    }

    StartScreenView::StartScreenView(std::shared_ptr<viewModel::StartScreenViewModel> sharedPtr) : viewModel(std::move(sharedPtr)) {
        windowHeaderText = viewModel->getTranslate("TITLE_F1");

        navigateToNextButtonText = viewModel->getTranslate("VIEW_StartScreen_navigateToNextButton");
        createNewRepositoryText = viewModel->getTranslate("VIEW_StartScreen_createNewRepositoryText");

        staffDirectoryText = viewModel->getTranslate("VIEW_GLOBAL_staffDirectoryText");

        staffDirectoryPath = viewModel->getStaffDirectory();

        createNewRepositoryCheckbox = ftxui::Checkbox(&createNewRepositoryText, viewModel->getCreateNewRepository());
        navigateToNextButton = ftxui::Button(fmt::format("{:^{}}", navigateToNextButtonText, navigateToNextButtonText.size()+4), [&]{ viewModel->useDefaultSettings(); });

        windowContainer = ftxui::Container::Vertical({
            createNewRepositoryCheckbox,
            navigateToNextButton
        });

        Add(windowContainer);

    }

    ftxui::Element StartScreenView::Render() {
        const theme::Theme& theme = viewModel->getTheme();
        using namespace ftxui;
        auto windowHeader = hbox({
                filler(),
                text(fmt::format("{:^{}}", windowHeaderText, 34)) | center | bold,
                filler()
        }) | bgcolor(theme.bg_primary) | color(theme.text_window_header) | borderStyled(theme.border_window_header);

        auto staffPath = vbox({
            filler() | size(HEIGHT, EQUAL, 1),
              text(staffDirectoryText) | hcenter,
              text("   " + staffDirectoryPath + "   ") | hcenter,
              filler() | size(HEIGHT, EQUAL, 1),
        }) | vcenter | borderStyled(ftxui::Color::GrayLight);

        auto buttons = vbox({
            hbox({ createNewRepositoryCheckbox->Render() | size(WIDTH, EQUAL, 30) }) | align_right | color(theme.text_base) |
                    bgcolor(theme.bg_primary),
            filler() | size(HEIGHT, EQUAL, 1),
            hbox({ navigateToNextButton->Render() | size(WIDTH, EQUAL, 30) }) | align_right | color(theme.text_success)
        });

        return vbox({
            windowHeader | size(HEIGHT, EQUAL, 5),
            vbox({
                filler() | size(HEIGHT, EQUAL, 6),
                hbox({staffPath}) | hcenter,
                filler() | size(HEIGHT, EQUAL, 6),
                vbox({
                    buttons
                })
            }) | borderStyled(theme.border_primary)
        }) | bgcolor(theme.bg_primary) | color(theme.text_primary);
    }
} // view