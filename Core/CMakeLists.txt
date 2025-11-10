set(HEADERS
    Color.hpp
    Point.hpp
    Image.hpp
    Window.hpp
    Drawable.hpp
)

set(SOURCES
    Window.cpp
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