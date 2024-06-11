#include "../header/MovieFilter.h"
#include <iterator>

void MovieFilterYearRange::filter(vector<Movie> &movies) {
    // First check if we have a valid range:
    if (lowerYearBound < 1850 || upperYearBound > 2024) {
        throw runtime_error("Input is not a valid year! Must be between 1850 and 2024.");
    }
    vector<Movie>::iterator moviePtr; //declare an iterator for the movieVector

    for (moviePtr = movies.begin(); moviePtr < movies.end();) {
        // Delete movies that do not match the input year (member variable)
        if (moviePtr->getYear() < lowerYearBound || moviePtr->getYear() > upperYearBound) {
            moviePtr = movies.erase(moviePtr);
        }
        else {
            moviePtr++;
        }
    }
}

void MovieFilterYearRange::filter(vector<Movie*> &movies) {
    // First check if we have a valid range:
    if (lowerYearBound < 1850 || upperYearBound > 2024) {
        throw runtime_error("Input is not a valid year! Must be between 1850 and 2024.");
    }
    vector<Movie*>::iterator moviePtr; //declare an iterator for the movieVector

    for (moviePtr = movies.begin(); moviePtr < movies.end();) {
        // Delete movies that do not match the input year (member variable)
        if ((*moviePtr)->getYear() < lowerYearBound || (*moviePtr)->getYear() > upperYearBound) {
            delete *moviePtr;
            moviePtr = movies.erase(moviePtr);
        }
        else {
            moviePtr++;
        }
    }
}