add_library(UI-ViewModel STATIC
        src/StartScreenViewModel.cpp
        include/StartScreenViewModel.hpp)

target_sources(UI-ViewModel PRIVATE
        src/BasicViewModel.cpp
        include/BasicViewModel.hpp
)
target_include_directories(UI-ViewModel PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(Boost REQUIRED signals2)
target_link_libraries(UI-ViewModel PRIVATE
        UI-Model
        Business-Core
        Boost::signals2
        Business-Theme
)