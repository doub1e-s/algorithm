cmake_minimum_required(VERSION 3.30)
project(OfferSolutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 确保使用指定的 C++ 标准

message("Build include directories: ${build_include_dirs}")

add_subdirectory(src)

add_executable(OfferSolutions main.cpp)

target_link_libraries(OfferSolutions PRIVATE OfferSolutionsLib)