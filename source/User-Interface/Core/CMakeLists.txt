add_library(UI-Core STATIC
        )

target_sources(UI-Core PRIVATE
        include/UserInterface.cpp
        include/UserInterface.hpp
        src/ScreenManager.cpp
        include/ScreenManager.hpp
)
target_include_directories(UI-Core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(Boost REQUIRED signals2)
#find_package(ftxui REQUIRED)
target_link_libraries(UI-Core PRIVATE
        UI-ViewModel
        UI-View
        ftxui::component
        ftxui::dom
        ftxui::screen
        Boost::signals2
        Business-Core
        Business-FileManagers
)
