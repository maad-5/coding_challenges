add_executable(strings
    palindromes_test.cpp
    palindromes.cpp
    palindromes.hpp
    parentheses_test.cpp
    parentheses.cpp
    parentheses.hpp

    main.cpp
)

target_compile_options(strings PRIVATE -Wall -Werror -g -pedantic-errors)
target_link_libraries(strings GTest::GTest)
gtest_discover_tests(strings)
