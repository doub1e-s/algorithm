project(algorithm_tests)

add_subdirectory(third_party/googletest-1.16.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

# 创建一个空的TEST_SOURCES目录
file(GLOB TEST_SOURCES "*.cpp")

add_executable(
        ${PROJECT_NAME}
        ${TEST_SOURCES}
)
target_link_libraries(
        algorithm_tests
        PRIVATE
        OfferSolutionsLib
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(algorithm_tests)