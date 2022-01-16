set(FMT_VERSION_TAG 8.1.1)
set(SPDLOG_VERSION_TAG v1.9.2)
set(PUGIXML_VERSION_TAG v1.11.4)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG ${FMT_VERSION_TAG}
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG ${SPDLOG_VERSION_TAG}
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
        pugixml
        GIT_REPOSITORY https://github.com/zeux/pugixml.git
        GIT_TAG ${PUGIXML_VERSION_TAG}
)
FetchContent_MakeAvailable(pugixml)

add_library(quickerfix FixConfigParser.cpp fix/Field.cpp fix/Fix.cpp)
target_compile_features(quickerfix PUBLIC cxx_std_20)
target_include_directories(quickerfix PUBLIC ${PROJECT_SOURCE_DIR}/include PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_options(quickerfix PRIVATE $<$<BOOL:${UNIX}>:-Wall -Wextra -Wpedantic>)
target_link_libraries(quickerfix pugixml::pugixml spdlog::spdlog fmt::fmt)
