# 子目录下引用了当前最新的gtest对应的tag
add_subdirectory(third_party/googletest-1.16.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

# 创建TEST_SOURCES目录并将当前目录下的所有cpp文件包括进去
file(GLOB TEST_SOURCES "*.cpp")

add_executable(
        ${PROJECT_NAME}
        ${TEST_SOURCES}
)
target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        # 链接项目中生成库，库的生成事public的，所以可以直接使用，不需要标注include路径
        OfferSolutionsLib
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME})