FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.0.1
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.9.0
)
FetchContent_MakeAvailable(spdlog)

add_library(quickerfix Hello.cpp)
target_compile_features(quickerfix PUBLIC cxx_std_20)
target_include_directories(quickerfix PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_options(quickerfix PRIVATE $<$<BOOL:${UNIX}>:-Wall -Wextra -Wpedantic>)
