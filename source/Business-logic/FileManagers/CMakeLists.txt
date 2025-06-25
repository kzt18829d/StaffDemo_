add_library(Business-FileManagers STATIC
        src/ThemeStorageProvider.cpp
        include/ThemeStorageProvider.hpp
        include/TranslateStorageProvider.cpp
        include/TranslateStorageProvider.hpp)

target_sources(Business-FileManagers PRIVATE
        src/StaffStorageProvider.cpp
        include/StaffStorageProvider.hpp
)

target_include_directories(Business-FileManagers PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(ftxui REQUIRED screen)
target_link_libraries(Business-FileManagers PRIVATE
        Business-Staff
        Business-Utils
        Business-Theme
        ftxui::screen
)