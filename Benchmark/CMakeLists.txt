include(FetchContent)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(benchmark)

file(GLOB BENCH_SOURCES CONFIGURE_DEPENDS *.cpp)

if(BENCH_SOURCES)
    foreach(bench_src ${BENCH_SOURCES})
        get_filename_component(bench_name ${bench_src} NAME_WE)
        add_executable(${bench_name} ${bench_src})
        target_link_libraries(${bench_name}
            PRIVATE
                benchmark::benchmark
                Core
                App
        )

        target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Source)
    endforeach()
else()
    message(WARNING "No benchmark source files found in benchmark/")
endif()
