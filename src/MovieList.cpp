#include "MovieList.h"


void MovieList::clearMovieVector() {
    for (Movie* moviePtr : movieVector) {
        delete moviePtr;
    }
    movieVector.clear();
}

MovieList::~MovieList() {
    clearMovieVector();
}

MovieList::MovieList(const MovieList& other) {
    for (const Movie* moviePtr : other.movieVector) {
        movieVector.push_back(new Movie(*moviePtr));
    }
}

MovieList& MovieList::operator=(const MovieList& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    clearMovieVector();
    for (const Movie* moviePtr : other.movieVector) {
        movieVector.push_back(new Movie(*moviePtr));
    }
    return *this;
}


