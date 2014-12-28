# .CMakeLists.txt
#
# Configuration file for the cross-platform build system "CMake".
#
# Copyright Florian Wolters 2014 (http://blog.florianwolters.de).
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(PROJECT_NAME "cpp-component-util-uncopyable")
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

project(${PROJECT_NAME}
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
        LANGUAGES CXX)

enable_language(CXX)
enable_testing()

include_directories("include")

set(PROJECT_TARGET_EXAMPLE_EXECUTABLE "uncopyable_mixin_example")
add_executable(${PROJECT_TARGET_EXAMPLE_EXECUTABLE}
               "example/fw/core/uncopyable_mixin_example.cc")
set_target_properties(${PROJECT_TARGET_EXAMPLE_EXECUTABLE} PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED ON)

set(REQUIRED_COMPILE_FEATURES
    cxx_defaulted_functions
    cxx_deleted_functions)

if(!WIN32)
    target_compile_features(${PROJECT_TARGET_EXAMPLE_EXECUTABLE}
                            PRIVATE ${REQUIRED_COMPILE_FEATURES})
endif()
