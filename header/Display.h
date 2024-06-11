#ifndef DISPLAY_H
#define DISPLAY_H

#include "../header/MovieFilter.h"
#include "MovieList.h"
using namespace std;

class Display {
public:
    ~Display(); // Destructor
    void primaryMenu(MovieList& movieList);
    void featureSelection(MovieList& movieList);
    void smartMatch();

    void displayRecResult(const vector<Movie>& movieList); // MO: This is the old display that I'm keeping to not break tests
    void displayRecResult(MovieList& movieList);

    // Input validations
    bool validStringInput(const string& input);
    bool validYesOrNo(string& input);

    // Helpers
    string GetValidStr();
    string GetValidYesOrNo();   // also validates
};

#endif
