add_library(User-Interface INTERFACE)

add_subdirectory(Core)
add_subdirectory(Model)
add_subdirectory(ViewModel)
add_subdirectory(View)

find_package(Boost REQUIRED signals2)

include(FetchContent)
FetchContent_Declare(
        ftxui GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui GIT_TAG main
)

FetchContent_MakeAvailable(ftxui)

target_link_libraries(User-Interface INTERFACE
        UI-Core
        UI-Model
        UI-ViewModel
        UI-View
        Boost::signals2
        ftxui::dom
        ftxui::screen
        ftxui::component
)