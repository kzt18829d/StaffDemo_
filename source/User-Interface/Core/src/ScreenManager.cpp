//
// Created by hid3h on 23.06.2025.
//

#include "../include/ScreenManager.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>

namespace core {
    ScreenManager::ScreenManager() {
        screenContainer = ftxui::Container::Stacked({});
        this->Add(screenContainer);
    }

    ScreenManager::~ScreenManager() = default;

    void ScreenManager::addScreen(ScreenType screenType, std::shared_ptr<view::BasicView> screen) {
        if (screen_map.contains(screenType)) return;
        screen_map[screenType] = screen;
        screenContainer->Add(screen);
    }

    void ScreenManager::showScreen(ScreenType screenType) {
        if (!screen_map.contains(screenType) || ACTIVE_SCREEN == screenType) return;
        ACTIVE_SCREEN = screenType;
        screenContainer->SetActiveChild(screen_map.at(screenType));
    }

    ftxui::Element ScreenManager::Render() {
        return screenContainer->ActiveChild()->Render();
    }

    bool ScreenManager::OnEvent(ftxui::Event event) {
        return ComponentBase::OnEvent(event);
    }

    std::string ScreenManager::getActiveScreenNameString() const {
        if (ACTIVE_SCREEN == ScreenType::NULL_SCREEN) return "No active screen";
        return "Screen"; // заглушка
    }

    ftxui::Component ScreenManager::getActiveScreenComponent() {
        if (ACTIVE_SCREEN == ScreenType::NULL_SCREEN) return nullptr;
        return screenContainer->ActiveChild();
    }

    ScreenType ScreenManager::getActiveScreenEnum() const {
        return ACTIVE_SCREEN;
    }
} // core