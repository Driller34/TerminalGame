set(HEADERS
    GameSettings.hpp
    Factory/Factory.hpp
    GameObjects/Mob.hpp
    GameObjects/Player.hpp
    Layers/GameLayer.hpp
    Game.hpp
)

set(SOURCES
    Factory/Factory.cpp
    GameObjects/Mob.cpp
    GameObjects/Player.cpp
    Layers/GameLayer.cpp
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

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} Core)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Source)