//
// Created by hid3h on 23.06.2025.
//

#ifndef STAFFDEMO_REFACTOR_SCREENMANAGER_HPP
#define STAFFDEMO_REFACTOR_SCREENMANAGER_HPP

#include <map>
#include <string>
#include <vector>
#include <ftxui/component/component_base.hpp>
#include "ScreenEnum.hpp"
#include "BasicView.hpp"


namespace core {

    ///@class ScreenManager
    ///@brief Менеджер управления представлениями
    ///@ingroup Core
    class ScreenManager : public ftxui::ComponentBase {
    private:
        ftxui::Component screenContainer;
        std::map<ScreenType, ftxui::Component> screen_map;
        ScreenType ACTIVE_SCREEN = ScreenType::NULL_SCREEN;

    public:
        ScreenManager();
        ~ScreenManager() override;

        void addScreen(ScreenType screenType, std::shared_ptr<view::BasicView> screen);
        void showScreen(ScreenType screenType);

        ftxui::Element Render();
        bool OnEvent(ftxui::Event) override;

        std::string getActiveScreenNameString() const;
        ftxui::Component getActiveScreenComponent();
        ScreenType getActiveScreenEnum() const;

        ScreenManager(ScreenManager &) = delete;
        ScreenManager(ScreenManager &&) = delete;
        ScreenManager &operator=(ScreenManager &) = delete;
        ScreenManager &operator=(ScreenManager &&) = delete;
    };

} // core

#endif //STAFFDEMO_REFACTOR_SCREENMANAGER_HPP
