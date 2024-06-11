#include "MovieFilter.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

void MovieFilterStar::filter(vector<Movie> & r){
    gatherResult(r, searchVector(starName, r), starName);
}
//Pointer version
void MovieFilterStar::filter(vector<Movie*> & r){
    gatherResult(r, searchVector(starName, r), starName);
}

int MovieFilterStar::searchVector(string input, const vector<Movie>& r){     // returns - 1 if search not found, else would return index where the first instance found...
    int result = -1;    

    for(int i = 0; i < r.size(); ++i){
        if(starNum == 1 && r.at(i).getStar1() == input){
            result = i;
            break;
        }
        if(starNum == 2 && r.at(i).getStar2() == input){
            result = i;
            break;
        }
    }

    return result;
}
// Pointer Version
int MovieFilterStar::searchVector(string input, const vector<Movie*>& r){     // returns - 1 if search not found, else would return index where the first instance found...
    int result = -1;    

    for(int i = 0; i < r.size(); ++i){
        if(starNum == 1 && r.at(i)->getStar1() == input){
            result = i;
            break;
        }
        if(starNum == 2 && r.at(i)->getStar2() == input){
            result = i;
            break;
        }
    }

    return result;
}

void MovieFilterStar::gatherResult(vector<Movie>& r, int firstOccurrence, string search){    // Starting from the first occurence, we gather all the movie that share the same star1 / star2 name.
    vector<Movie> temp = {};
    if(firstOccurrence != -1){
        for(int i = firstOccurrence; i < r.size(); ++i){
            if(starNum == 1 && r.at(i).getStar1() == search){
                temp.push_back(r.at(i));
            }
            if(starNum == 2 && r.at(i).getStar2() == search){
                temp.push_back(r.at(i));
            }
        }
    }
    r = temp;   // returns empty vector if starName was not originally found
}

//Pointer Version
void MovieFilterStar::gatherResult(vector<Movie*>& r, int firstOccurrence, string search){    // Starting from the first occurence, we gather all the movie that share the same star1 / star2 name.
    vector<Movie*> temp;
    vector<Movie*> trashVector; 
    for(int i = 0; i < r.size(); ++i){
        if(starNum == 1 && r.at(i)->getStar1() == search){
            temp.push_back(r.at(i));
        }
        else if(starNum == 2 && r.at(i)->getStar2() == search){
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