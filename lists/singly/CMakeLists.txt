add_executable(singly
    reverse_test.cpp
    reverse.cpp
    reverse.hpp
    singly.cpp
    singly.hpp

    main.cpp
)

target_compile_options(singly PRIVATE -Wall -Werror -Wextra -pedantic-errors)
target_link_libraries(singly GTest::GTest)
gtest_discover_tests(singly)
