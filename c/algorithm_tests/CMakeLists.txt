add_executable (algorithm_tests algorithm_tests.c ../dependencies/munit/munit.c)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (algorithm_tests LINK_PUBLIC pkealgorithms)