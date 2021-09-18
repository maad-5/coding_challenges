add_executable(hash_table
        hash_table_test.cpp
        hash_table.hpp

        main.cpp
        )

target_compile_options(design PRIVATE -Wall -Werror -Wextra -pedantic-errors)
target_link_libraries(hash_table GTest::GTest)
gtest_discover_tests(hash_table)
