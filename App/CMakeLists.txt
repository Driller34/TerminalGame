set(SOURCES
    Main.cpp
)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${SOURCES})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#target_link_libraries(App Core)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Source)