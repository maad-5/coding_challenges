add_executable(sorts
    bubble_test.cpp
    bubble.cpp
    bubble.hpp
    heap_test.cpp
    heap.cpp
    heap.hpp
    insertion_test.cpp
    insertion.cpp
    insertion.hpp
    merge_test.cpp
    merge.cpp
    merge.hpp
    quick_test.cpp
    quick.cpp
    quick.hpp
    selection_test.cpp
    selection.cpp
    selection.hpp

    sorts.hpp
    main.cpp
)

target_compile_options(sorts PRIVATE -Wall -Werror -g -pedantic-errors)
target_link_libraries(sorts GTest::GTest)
gtest_discover_tests(sorts)
