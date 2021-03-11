add_executable(design
    lru_cache_test.cpp
    lru_cache.cpp
    lru_cache.hpp

    main.cpp
)

target_link_libraries(design GTest::GTest)
gtest_discover_tests(design)
