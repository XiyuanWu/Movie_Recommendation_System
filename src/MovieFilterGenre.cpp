#include "MovieFilter.h"
#include <algorithm>
#include <cctype>

//help cinvert a string to lower case
string MovieFilterGenre::toLower(const string& str) const {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int MovieFilterGenre::searchVector(const string& input, const vector<Movie>& movies) {
    string lowerInput = toLower(input);
    for (int i = 0; i < movies.size(); ++i) {
        if (toLower(movies[i].getGenre()) == lowerInput) {
            return i;
        }
    }
    return -1;
}

int MovieFilterGenre::searchVector(const string& input, const vector<Movie*>& movies) {
    string lowerInput = toLower(input);
    for (int i = 0; i < movies.size(); ++i) {
        if (toLower(movies[i]->getGenre()) == lowerInput) {
            return i;
        }
    }
    return -1;
}

void MovieFilterGenre::gatherResult(vector<Movie>& movies, int firstOccurrence, const string& search) {
    vector<Movie> temp;
    string lowerSearch = toLower(search);
    if (firstOccurrence != -1) {
        for (int i = firstOccurrence; i < movies.size(); ++i) {
            if (toLower(movies[i].getGenre()) == lowerSearch) {
                temp.push_back(movies[i]);
            }
        }
    }
    movies = temp;
}

void MovieFilterGenre::gatherResult(vector<Movie*>& movies, int firstOccurrence, const string& search) {
    vector<Movie*> temp;
    vector<Movie*> trashVector;
    string lowerSearch = toLower(search);

    for (int i = 0; i < movies.size(); ++i) {
        if (toLower(movies[i]->getGenre()) == lowerSearch) {
            temp.push_back(movies[i]);
        } else {
            trashVector.push_back(movies[i]);
        }
    }

    // Deallocate movies not in temp
    for (Movie* movie : trashVector) {
        delete movie;
    }

    movies = temp;
}

void MovieFilterGenre::filter(vector<Movie>& movies) {
    gatherResult(movies, searchVector(genreName, movies), genreName);
}

void MovieFilterGenre::filter(vector<Movie*>& movies) {
    gatherResult(movies, searchVector(genreName, movies), genreName);
}
