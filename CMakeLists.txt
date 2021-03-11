cmake_minimum_required(VERSION 3.16)

project(coding_challenges_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

add_subdirectory(design)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_SHOW_INCLUDE_FILES NO)
    set(DOXYGEN_HAVE_DOT NO)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_USE_MATHJAX YES)

    doxygen_add_docs(doc)
endif(DOXYGEN_FOUND)
