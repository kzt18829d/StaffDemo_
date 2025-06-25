add_library(Business-Staff STATIC)

target_sources(Business-Staff PRIVATE
        src/IEmployee.cpp
        include/IEmployee.hpp
        include/StaffInterfaces.hpp
        src/IPersonal.cpp
        include/IPersonal.hpp
        src/Personal.cpp
        include/Personal.hpp
        src/IEngineer.cpp
        include/IEngineer.hpp
        src/Project.cpp
        include/Project.hpp
        src/Engineer.cpp
        include/Engineer.hpp
        src/Manager.cpp
        include/Manager.hpp
        include/TempEmplyee.hpp
        include/TempProject.hpp
)

target_include_directories(Business-Staff PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
