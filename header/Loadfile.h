#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "MovieList.h"

using namespace std;

class LoadFile {
 private:
    
 public:
    bool isCSVFileType(const string &);
    void loadMoviesFromFile(MovieList &, const string &);
};