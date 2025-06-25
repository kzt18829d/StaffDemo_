add_library(Business-Theme INTERFACE)

#target_sources(Business-Theme PRIVATE
#        include/ThemeColor.hpp
#        include/Theme.hpp
#)

target_include_directories(Business-Theme INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#find_package(ftxui REQUIRED screen)
target_link_libraries(Business-Theme INTERFACE
        ftxui::screen

)