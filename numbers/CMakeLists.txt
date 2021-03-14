add_executable(numbers
    digital_root_test.cpp
    digital_root.cpp
    digital_root.hpp
    largest_binary_gap_test.cpp
    largest_binary_gap.cpp
    largest_binary_gap.hpp
    roman_numerals_test.cpp
    roman_numerals.cpp
    roman_numerals.hpp

    main.cpp
)

target_compile_options(numbers PRIVATE -Wall -Werror -g -pedantic-errors)
target_link_libraries(numbers GTest::GTest)
gtest_discover_tests(numbers)
