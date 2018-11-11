add_library(pkealgorithms SHARED algorithms/algorithms.h data_structures/data_structures.h algorithms/graham_scan.h algorithms/graham_scan.c data_structures/pke_list.c data_structures/pke_list.h data_structures/pke_stack.h data_structures/pke_planar_objects.h data_structures/pke_stack.c)

target_include_directories (pkealgorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS pkealgorithms DESTINATION lib)