#pragma once

#include "Movie.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


class MovieFilter {
    public:
     virtual ~MovieFilter() = default;
     int breakNum = 1;      // for director and star filter to break out of filtering process (the for loop under big do while loop of display featureSelection)
     
     virtual void filter(vector<Movie*> &) = 0; // MO: This is a pure virtual function to be implemented in subclasses.
     const int getBreakNum() {return breakNum;}
};

class MovieFilterGenre : public MovieFilter{
    private:
    string genreName;

    // Helper function to convert a string to lowercase
    string toLower(const string& str) const;

public:
    ~MovieFilterGenre() override = default;
    void setGenreName(const string& newInput) { genreName = toLower(newInput); }
    const string& getGenreName() { return genreName; }

    void filter(vector<Movie>&);
    void filter(vector<Movie*>&);

    int searchVector(const string&, const vector<Movie>&); // returns -1 if genre not found, else returns index of first occurence 
    int searchVector(const string&, const vector<Movie*>&);
    void gatherResult(vector<Movie>&, int, const string&); // gathers all movies matching the genre
    void gatherResult(vector<Movie*>&, int, const string&);
};

class MovieFilterRating : public MovieFilter{
    private:
     double lowerBound;
     double upperBound;
    public:
     ~MovieFilterRating() override = default;
     void setLowerBound(double newInput) {lowerBound = newInput;}
     void setUpperBound(double newInput) {upperBound = newInput;}
     const double getLowerBound() {return lowerBound;}
     const double getUpperBound() {return upperBound;}
     void filter(vector<Movie> &);
     void filter(vector<Movie*>&);
};

class MovieFilterDirector : public MovieFilter{
    private:
     string directorName;

    public:
     ~MovieFilterDirector() override = default;
     void setDirectorName(const string &newInput) {directorName = newInput;} // setting void and return 0 if not valid
     const string& getDirectorName() {return directorName;}

     void setBreakNum(int num){breakNum = num;}

     void filter(vector<Movie> &);
     void filter(vector<Movie*> & r);

     int searchVector(string, const vector<Movie>&); // returns - 1 if star name not found, else would return index where the first instance found...
     int searchVector(const string&, const vector<Movie*>&);
     void gatherResult(vector<Movie>&, int, string); // gathers all search related movies here
     void gatherResult(vector<Movie*>&, int, const string&);
};

class MovieFilterStar : public MovieFilter{
    private:
     string starName;
     int starNum;
    public:
     ~MovieFilterStar() override = default;
     void setStarNum(int num) {starNum = num;}
     const int getStarNum() {return starNum;}

     void setStarName(const string &newInput){starName = newInput;}
     const string& getStarName() {return starName;}

     void setBreakNum(int num){breakNum = num;}

     void filter(vector<Movie> & r);
     void filter(vector<Movie*> & r);

     int searchVector(string, const vector<Movie>&); // returns - 1 if star name not found, else would return index where the first instance found...
     int searchVector(string, const vector<Movie*>&);
     void gatherResult(vector<Movie>&, int, string); // gathers all search related movies here
     void gatherResult(vector<Movie*>&, int, string);
};

class MovieFilterYear : public MovieFilter{
    private:
     int singleYear;
    public:
     ~MovieFilterYear() override = default;
     void setYear(int newInput) {singleYear = newInput;}
     const int getYear() {return singleYear;}
     void filter(vector<Movie> &); // Used for testing purposes
     void filter(vector<Movie*> &);
};

class MovieFilterYearRange : public MovieFilter {
    private:
     int lowerYearBound;
     int upperYearBound;
    public:
     ~MovieFilterYearRange() override = default;
     void setLowerBound(int newInput) {lowerYearBound = newInput;}
     void setUpperBound(int newInput) {upperYearBound = newInput;}
     const int getLowerBound() {return lowerYearBound;}
     const int getUpperBound() {return upperYearBound;}
     void filter(vector<Movie> &);
     void filter(vector<Movie*> &);
};
