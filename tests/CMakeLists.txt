project(my_gtest)

add_subdirectory(third_party/googletest-1.16.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(
        algorithm_tests
        algorithm_tests.cpp
)
target_link_libraries(
        algorithm_tests
        PRIVATE
        OfferSolutionsLib
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(algorithm_tests)