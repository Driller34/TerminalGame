file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    Utils/*.hpp
    Factory/*.hpp
    GameObjects/*.hpp
    SpaceInvader/*.hpp
    Layers/*.hpp
    Game.hpp
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    Factory/*.cpp
    Utils/*.cpp
    GameObjects/*.cpp
    SpaceInvader/*.cpp
    Layers/*.cpp
    Game.cpp
    Main.cpp
)

add_library(App STATIC)

target_sources(App 
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES ${HEADERS}
)

target_link_libraries(App PUBLIC Core)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} Core App)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Source)
