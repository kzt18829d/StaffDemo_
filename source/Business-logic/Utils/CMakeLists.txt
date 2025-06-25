add_library(Business-Utils STATIC
        )

target_sources(Business-Utils PRIVATE
        include/Spliter.hpp
        src/Spliter.cpp
        include/TimeUtils.cpp
        include/TimeUtils.hpp
        include/json.hpp
)

target_include_directories(Business-Utils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
