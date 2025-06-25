//
// Created by hid3h on 25.06.2025.
//

#include "UserInterface.hpp"
#include "StartScreenView.hpp"
#include "TranslateStorageProvider.hpp"
#include <iostream>

namespace core {
    void UserInterface::initModels() {
        appSettings = std::make_shared<core::AppSettings>();
        screenManager = std::make_unique<ScreenManager>();
    }

    void UserInterface::initFunctions() {
        reRenderFunction = [&]{ screenInteractive.PostEvent(ftxui::Event::Custom); };
    }

    void UserInterface::loadTranslates() {
        try {
            fileManager::TranslateStorageProvider storageProvider(appSettings->getLocalizationDirectory());
            storageProvider.loadFromJson();
        } catch (std::exception &ex) {
            std::cerr << std::string(ex.what()) << std::endl;
            system("pause");
            exit(-1384);
        }
    }

    void UserInterface::loadThemes() {

    }

    void UserInterface::initTranslates() {

    }

    void UserInterface::initThemes() {

    }

    void UserInterface::initScreens() {

        // startScreen
        startScreenViewModel = std::make_shared<viewModel::StartScreenViewModel>(appSettings);
        auto startScreenView = std::make_shared<view::StartScreenView>(startScreenViewModel);
        screenManager->addScreen(ScreenType::START_SCREEN, startScreenView);

        screenManager->showScreen(ScreenType::START_SCREEN);
    }

    void UserInterface::initSignals() {
        appSettings->themeManager->themeChangedSignal.connect(reRenderFunction);
    }

    UserInterface::UserInterface() : screenInteractive(ftxui::ScreenInteractive::TerminalOutput()) {
        initModels();
        loadTranslates();
        initTranslates();
        initScreens();
    }

    UserInterface::~UserInterface() = default;

    void UserInterface::run() {
        screenInteractive.ExitLoopClosure();
        screenInteractive.Loop(screenManager->getActiveScreenComponent());
    }


} // core