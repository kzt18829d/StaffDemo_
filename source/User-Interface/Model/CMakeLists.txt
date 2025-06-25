add_library(UI-Model STATIC)

target_sources(UI-Model PRIVATE
        src/BasicModel.cpp
        include/BasicModel.hpp
)

target_include_directories(UI-Model PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

