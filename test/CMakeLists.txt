set(GOOGLETEST_VERSION_TAG release-1.11.0)
set(APPROVALTESTS_VERSION_TAG v.10.12.1)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ${GOOGLETEST_VERSION_TAG}
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
        ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG ${APPROVALTESTS_VERSION_TAG}
)
FetchContent_MakeAvailable(ApprovalTests)

add_executable(runner TestFixConfigParser.t.cpp)
target_link_libraries(runner gtest_main gmock ApprovalTests::ApprovalTests quickerfix)

include(GoogleTest)
gtest_discover_tests(runner)
