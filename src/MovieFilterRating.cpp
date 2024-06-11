#include "../header/MovieFilter.h"
#include <stdexcept>
#include <iterator>

void MovieFilterRating::filter(vector<Movie>& movies) {
    // First check if we have valid rating bounds:
    if (lowerBound < 0 || upperBound > 10 || lowerBound > upperBound) {
        throw runtime_error("Input is not a valid rating range! Lower bound must be >= 0, upper bound <= 10, and lower <= upper.");
    }
    vector<Movie>::iterator moviePtr; // Declare an iterator for the movie vector

    for (moviePtr = movies.begin(); moviePtr < movies.end();) {
        // Delete movies that do not match the input rating range
        if (moviePtr->getRating() < lowerBound || moviePtr->getRating() > upperBound) {
            moviePtr = movies.erase(moviePtr);
        } else {
            moviePtr++;
        }
    }
}

void MovieFilterRating::filter(vector<Movie*>& movies) {
    if (lowerBound < 0 || upperBound > 10 || lowerBound > upperBound) {
        throw std::runtime_error("Input is not a valid rating range! Lower bound must be >= 0, upper bound <= 10, and lower <= upper.");
    }
    vector<Movie*>::iterator moviePtr;

    for (moviePtr = movies.begin(); moviePtr < movies.end();) {
        if ((*moviePtr)->getRating() < lowerBound || (*moviePtr)->getRating() > upperBound) {
            delete *moviePtr;
            moviePtr = movies.erase(moviePtr);
        } else {
            moviePtr++;
        }
    }
}