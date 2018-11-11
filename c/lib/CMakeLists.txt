add_library(pkealgorithms SHARED algorithms/pke_algorithms.h data_structures/pke_data_structures.h algorithms/pke_graham_scan.h algorithms/pke_graham_scan.c data_structures/pke_list.c data_structures/pke_list.h data_structures/pke_stack.h data_structures/pke_planar_objects.h data_structures/pke_stack.c algorithms/pke_planar_opeartions.h)

target_include_directories (pkealgorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS pkealgorithms DESTINATION lib)