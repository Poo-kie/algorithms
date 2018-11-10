add_library(pkealgorithms SHARED algorithms/algorithms.c algorithms/algorithms.h data_structures/data_structures.h data_structures/data_structures.c)

target_include_directories (pkealgorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS pkealgorithms DESTINATION lib)