file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    Base/*.hpp
    ECS/*.hpp
    Graphic/*.hpp
    GUI/*.hpp
    Layers/*.hpp
    Loader/*.hpp
    Utils/*.hpp
    ResourceManager.hpp
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ECS/*.cpp
    Graphic/*.cpp
    GUI/*.cpp
    Layers/*.cpp
    Loader/*.cpp
    Utils/*.cpp
    ResourceManager.cpp
)

add_library(Core STATIC)

target_sources(Core 
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES ${HEADERS}
)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADERS} ${SOURCES})

add_subdirectory(Sandbox)