add_executable (data_structure_tests data_structure_tests.c ../dependencies/munit/munit.c)

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (data_structure_tests LINK_PUBLIC pkealgorithms)