#add_compile_options(-std=c++11)
#add_library(region_grow SHARED region_grow.cpp)
#set_target_properties(region_grow PROPERTIES PUBLIC_HEADER "region_grow.h")
#target_link_libraries(region_grow)

#install(TARGETS region_grow
#  LIBRARY DESTINATION lib
#  PUBLIC_HEADER DESTINATION include/region_grow)

#if(BUILD_TESTING)
FIND_PACKAGE(OpenCV)
INCLUDE_DIRECTORIES(${OpenCV})
add_executable(assignment assignment.cpp otsu.cpp threshold.cpp two_steps_thinning.cpp get_histograph.cpp)
target_link_libraries(assignment ${OpenCV_LIBS})
add_test(assignment ${CMAKE_BINARY_DIR}/bin/assignment)
#endif()
