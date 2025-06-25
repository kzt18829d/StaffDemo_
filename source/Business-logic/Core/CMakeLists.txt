add_library(Business-Core STATIC
        src/TranslateManager.cpp
        include/TranslateManager.hpp
        ../Theme/include/Theme.hpp
        ../Theme/include/ThemeColor.hpp
        src/ThemeManager.cpp
        include/ThemeManager.hpp
        include/ScreenEnum.hpp
        src/AppSettings.cpp
        include/AppSettings.hpp
)

target_sources(Business-Core PRIVATE


)

target_include_directories(Business-Core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(Boost REQUIRED signals2)

target_link_libraries(Business-Core PRIVATE
        Business-Utils
        Business-Repository
        Business-FileManagers
        Business-Theme
        Boost::signals2
)
