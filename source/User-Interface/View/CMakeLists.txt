add_library(UI-View STATIC
        )

target_sources(UI-View PRIVATE
        src/BasicView.cpp
        include/BasicView.hpp
        src/StartScreenView.cpp
        include/StartScreenView.hpp
)
target_include_directories(UI-View PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#find_package(ftxui REQUIRED)
find_package(fmt REQUIRED)
target_link_libraries(UI-View PRIVATE
        UI-ViewModel
        ftxui::dom
        ftxui::component
        ftxui::screen
        fmt::fmt
)