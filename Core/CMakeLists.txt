set(HEADERS
    Utils/Color.hpp
    Utils/Vec.hpp
    Utils/Clock.hpp
    Utils/RNG.hpp
    Graphic/Image.hpp
    Loader/BMP.hpp
    Loader/BMPLoader.hpp
    Base/Drawable.hpp
    Base/Transformable.hpp
    GUI/Rectangle.hpp
    GUI/ProgressBar.hpp
    ECS/World.hpp
    ECS/System.hpp
    Graphic/Window.hpp
    Graphic/Sprite.hpp
    Utils/Input.hpp
    Layers/Layer.hpp
    Layers/LayerManager.hpp
    Layers/PauseLayer.hpp
    Layers/MenuLayer.hpp
    Layers/LayerManager.hpp
    ResourceManager.hpp
)

set(SOURCES
    Utils/Clock.cpp
    Utils/RNG.cpp
    GUI/Rectangle.cpp
    GUI/ProgressBar.cpp
    ECS/World.cpp
    ECS/System.cpp
    Graphic/Window.cpp
    Graphic/Sprite.cpp
    Loader/BMP.cpp
    Loader/BMPLoader.cpp
    Layers/LayerManager.cpp
    ResourceManager.cpp
    Layers/MenuLayer.cpp
    Layers/PauseLayer.cpp
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