cmake_minimum_required(VERSION 2.6)
project(descriptor)
# opencv 
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

message(STATUS "Opencv include dir found at ${OpenCV_INCLUDE_DIRS}")
message(STATUS "Opencv lib dir found at ${OpenCV_LIBS}")

add_executable(descriptor descriptor_extractor_matcher.cpp)
target_link_libraries( descriptor ${OpenCV_LIBS} )
install(TARGETS descriptor RUNTIME DESTINATION bin)
