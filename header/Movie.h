#ifndef MOVIE_H
#define MOVIE_H

#include <string>
// inclde header

using namespace std;

class Movie {
private:
    string title;
    int year;
    string genre;
    double rating;
    string director;
    string star1;
    string star2;

public:
    // Constructor
    Movie(string title = "", int year = 0, string genre = "", double rating = 0, string director = "", string star1 = "", string star2 = "")
        : title(title), year(year), genre(genre), rating(rating), director(director), star1(star1), star2(star2) {}

    // Destructor
    ~Movie() {}

    string getTitle() const     { return title; }
    int getYear() const         { return year; }
    string getGenre() const     { return genre; }
    double getRating() const    { return rating; }
    string getDirector() const  { return director; }
    string getStar1() const     { return star1; }
    string getStar2() const     { return star2; }

    void setTitle(string t) {title = t;}
    void setYear(int y) {year = y;}
    void setGenre(string g) {genre = g; }
    void setRating(double r) {rating = r; }
    void setDirector(string d) {director = d; }
    void setStar1(string s1) {star1 = s1; }
    void setStar2(string s2) {star2 = s2; }

    bool operator==(const Movie& other) const {
        return title == other.title && year == other.year && genre == other.genre && 
               rating == other.rating && director == other.director && 
               star1 == other.star1 && star2 == other.star2;
    }
};

#endif
