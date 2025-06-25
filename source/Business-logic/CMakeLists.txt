add_library(Business-Logic INTERFACE)

add_subdirectory(Core)
add_subdirectory(FileManagers)
add_subdirectory(Repository)
add_subdirectory(Staff)
add_subdirectory(Utils)
add_subdirectory(Theme)


target_link_libraries(Business-Logic INTERFACE
        Business-Core
        Business-FileManagers
        Business-Repository
        Business-Staff
        Business-Utils
        Business-Theme
)