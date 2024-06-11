cmake_minimum_required(VERSION 3.10)
project(MovieRec)

add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include_directories(${CMAKE_SOURCE_DIR}/header)
link_directories(${LIBRARY_OUTPUT_PATH})

# R.Z.: Save the below until we are ready to test MovieFilter.cpp and other.cpp 
add_subdirectory(src)
add_subdirectory(test)


# R.Z.: Save the below until everything is ready...
# add_executable(MovieRec main.cpp)

# target_link_libraries(MovieRec gmock gtest gtest_main)
# R.Z.: above is a necessary line whenever you add an executable??



