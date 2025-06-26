cmake_minimum_required(VERSION 3.30)
project(OfferSolutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 确保使用指定的 C++ 标准

message("Build include directories: ${build_include_dirs}")

if (MSVC)
    add_compile_options("$<$<COMPILE_LANGUAGE:C,CXX>:/utf-8>")
endif()

add_subdirectory(src)

add_subdirectory(tests)