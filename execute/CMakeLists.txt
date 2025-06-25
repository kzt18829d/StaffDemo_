add_executable(Execute main.cpp)

target_link_libraries(Execute PRIVATE
        User-Interface
        Business-Logic
        Business-Theme
)