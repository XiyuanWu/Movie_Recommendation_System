#ifndef MOVIELIST_H
#define MOVIELIST_H

#pragma once

#include "Movie.h"
#include <vector>
using namespace std;

class MovieList {
private:
    vector<Movie*> movieVector;
    void clearMovieVector(); // helper function for delete
public:
    MovieList() {};
    //MO: Adding the rule of three for movie list because we need a special destructor to deallocate memory.
    ~MovieList(); // Destructor
    MovieList(const MovieList&); // copy constructor
    MovieList& operator=(const MovieList&); // assignment operator
    //MO: 2 get movie vectors to prevent compiler from yelling at us
    vector<Movie*>& getMovieVector()  {return movieVector;}
    const vector<Movie*>& getMovieVector() const {return movieVector;}
    void setMovieVector(const vector<Movie*>& movies) { movieVector = movies; }
    void addMovie(Movie *moviePtr) {movieVector.push_back(moviePtr);}

    void clearMovies() { clearMovieVector(); } //exposing clearMovieVector in public for testing purpose
};

#endif
