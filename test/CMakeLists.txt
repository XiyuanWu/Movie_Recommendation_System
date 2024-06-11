cmake_minimum_required(VERSION 3.10)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/src")

include_directories(${CMAKE_SOURCE_DIR}/header)
link_directories(${LIBRARY_OUTPUT_PATH})

add_executable(runClassTests
  testMovie.cpp
  testDisplay.cpp
  testMovieFilterStar.cpp
  testMovieFilterYear.cpp
  testMovieFilterYearRange.cpp
  testMovieFilterDirector.cpp
  testMovieList.cpp
  testLoadFile.cpp
  testMovieFilterRating.cpp
  testMovieFilterGenre.cpp
)

add_executable( runDemo
  Demo.cpp
)

# R.Z.: How to run the executable? Try ./bin/runClassTests

target_link_libraries(runClassTests gmock gtest gtest_main)

# R.Z.: Add the below when you're running test on <class>.cpp 
target_link_libraries(runClassTests simpleLibrary)

target_link_libraries(runDemo simpleLibrary)

