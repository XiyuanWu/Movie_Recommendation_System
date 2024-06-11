#include "MovieFilter.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

void MovieFilterDirector::filter(vector<Movie> & r){
    gatherResult(r, searchVector(directorName, r), directorName);
}

void MovieFilterDirector::filter(vector<Movie*> & r){
    gatherResult(r, searchVector(directorName, r), directorName);
}

int MovieFilterDirector::searchVector(string input, const vector<Movie>& r){     // returns - 1 if search not found, else would return index where the first instance found...
    int result = -1;    

    for(int i = 0; i < r.size(); ++i){
        if(r.at(i).getDirector() == input){
            result = i;
            break;
        }
    }

    return result;
}
// Pointer Version
int MovieFilterDirector::searchVector(const string &input, const vector<Movie*>& r){     // returns - 1 if search not found, else would return index where the first instance found...
    int result = -1;    

    for(int i = 0; i < r.size(); ++i){
        if(r.at(i)->getDirector() == input){
            result = i;
            break;
        }
    }

    return result;
}


void MovieFilterDirector::gatherResult(vector<Movie>& r, int firstOccurrence, string search){    // Starting from the first occurence, we gather all the movie that share the same directorName
    vector<Movie> temp = {};
    if(firstOccurrence != -1){
        for(int i = firstOccurrence; i < r.size(); ++i){
            if(r.at(i).getDirector() == search){
                temp.push_back(r.at(i));
            }
        }
    }
    r = temp;   // returns empty vector if directorName was not originally found
}

//Pointer Version
void MovieFilterDirector::gatherResult(vector<Movie*>& r, int firstOccurrence, const string &search){    // Starting from the first occurence, we gather all the movie that share the same star1 / star2 name.
    vector<Movie*> temp;
    vector<Movie*> trashVector;
    for(int i = 0; i < r.size(); ++i){
        if(r.at(i)->getDirector() == search){
            temp.push_back(r.at(i));
        }
        else {
            trashVector.push_back(r.at(i));
        }
    }

    for (Movie* movie : trashVector) {
            delete movie;
    }
    r = temp;
}