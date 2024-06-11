# R.Z.: Add the following once you are running test on <class>.cpp. 
# R.Z.: The name simpleLibrary must match target_link_libraries in test/CMakeLists.txt

add_library(simpleLibrary
  MovieFilterYear.cpp
  MovieFilterYearRange.cpp
  MovieFilterStar.cpp
  MovieList.cpp
  Display.cpp
  MovieFilterDirector.cpp
  LoadFile.cpp
  MovieFilterGenre.cpp
  MovieFilterRating.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})


