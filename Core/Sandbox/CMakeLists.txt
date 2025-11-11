file(GLOB SANDBOX_SOURCES CONFIGURE_DEPENDS *.cpp)

foreach(sandbox_src ${SANDBOX_SOURCES})
    get_filename_component(name ${sandbox_src} NAME_WE)
    add_executable(${name} ${sandbox_src})
    target_link_libraries(${name} PRIVATE Core)
endforeach()