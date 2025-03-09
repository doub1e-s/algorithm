# CMakeLists.txt in src/

# 添加源文件
set(SOURCES
        01_assign_op.cpp
        02_singleton.cpp
)

# 创建一个库，如果需要的话
add_library(OfferSolutionsLib STATIC ${SOURCES})

target_include_directories(OfferSolutionsLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# 如果需要链接其他库
# target_link_libraries(OfferSolutionsLib other_lib)