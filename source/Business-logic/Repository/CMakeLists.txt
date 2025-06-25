add_library(Business-Repository STATIC

        )

target_sources(Business-Repository PRIVATE
        src/StaffRepository.cpp
        include/StaffRepository.hpp
        src/ProjectRepository.cpp
        include/ProjectRepository.hpp
        src/RepositoryInstruments.cpp
        include/RepositoryInstruments.hpp
)

target_include_directories(Business-Repository PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Business-Repository PRIVATE
        Business-Staff
        Business-Utils
)