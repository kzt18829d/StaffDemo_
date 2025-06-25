#ifndef STAFFDEMO_REFACTOR_USERINTERFACE_HPP
#define STAFFDEMO_REFACTOR_USERINTERFACE_HPP

#include <ftxui/component/screen_interactive.hpp>
#include "ScreenManager.hpp"
#include "AppSettings.hpp"
#include <functional>

#include "StartScreenViewModel.hpp"


namespace core {

    ///@class UserInterface
    ///@brief Главный класс программы
    ///@addtogroup Core
    class UserInterface {
    private:
        void initModels();              ///< Инициализация моделей
        void loadTranslates();          ///< Подгрузка переводов из JSON
        void loadThemes();              ///< Подгрузка тем из JSON
        void initTranslates();          ///< Инициализация переводов в TranslationManager @see TranslationManager
        void initThemes();              ///< Инициализация тем в ThemeManager @see ThemeManager
        void initScreens();             ///< Инициализация ViewModels&Views
        void initSignals();             ///< Подключение глобальных сигналов
        void initFunctions();           ///< Инициализация дополнительных функций

        ftxui::ScreenInteractive screenInteractive;
        std::unique_ptr<ScreenManager> screenManager;

        std::shared_ptr<core::AppSettings> appSettings;

        std::function<void()> reRenderFunction;

        std::shared_ptr<viewModel::StartScreenViewModel> startScreenViewModel;



        boost::signals2::connection updateViewRequestConnection;
        boost::signals2::connection navigateFromLoadRepositoryScreen;
        boost::signals2::connection navigateFromBaseScreen;
        boost::signals2::connection navigateFromStartScreenConnection;
        boost::signals2::connection exitConnection;

    public:
        UserInterface();
        ~UserInterface();

        void run();
    };


} // core

#endif //STAFFDEMO_REFACTOR_USERINTERFACE_HPP
