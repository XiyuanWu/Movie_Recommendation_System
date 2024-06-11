#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

using namespace testing;

Movie a1("The Shawshank Redemption", 1994, "Drama", 9.3, "Frank Darabont", "Tim Robbins", "Morgan Freeman");
Movie a2("The Godfather", 1972, "Crime", 9.2, "Francis Ford Coppola", "Marlon Brando", "Al Pacino");
Movie a3("The Dark Knight", 2008, "Action", 9.0, "Christopher Nolan", "Christian Bale", "Heath Ledger");
Movie a4("12 Angry Men", 1957, "Drama", 8.9, "Sidney Lumet", "Henry Fonda", "Lee J. Cobb");
Movie a5("Schindler's List", 1993, "Biography", 8.9, "Steven Spielberg", "Liam Neeson", "Ralph Fiennes");

Movie a6("The Lord of the Rings: The Return of the King", 2003, "Adventure", 8.9, "Peter Jackson", "Elijah Wood", "Viggo Mortensen");
Movie a7("Pulp Fiction", 1994, "Crime", 8.9, "Quentin Tarantino", "John Travolta", "Uma Thurman");
Movie a8("The Good, the Bad and the Ugly", 1966, "Western", 8.8, "Sergio Leone", "Clint Eastwood", "Eli Wallach");
Movie a9("The Lord of the Rings: The Fellowship of the Ring", 2001, "Adventure", 8.8, "Peter Jackson", "Elijah Wood", "Ian McKellen");

TEST(RatingFilterTests, ValidRatingRange) {
    vector<Movie> movies = {a1, a2, a3, a4, a5, a6, a7, a8, a9};
    MovieFilterRating rFilter;
    rFilter.setLowerBound(8.9);
    rFilter.setUpperBound(9.3);
    rFilter.filter(movies);
    EXPECT_THAT(movies, ElementsAre(a1, a2, a3, a4, a5, a6, a7));
}

TEST(RatingFilterTests, BadLowerBound) {
    vector<Movie> movies = {a1, a2, a3, a4, a5, a6, a7, a8, a9};
    MovieFilterRating rFilter;
    rFilter.setLowerBound(-1.0);
    rFilter.setUpperBound(9.3);
    EXPECT_ANY_THROW(rFilter.filter(movies));
}

TEST(RatingFilterTests, BadUpperBound) {
    vector<Movie> movies = {a1, a2, a3, a4, a5, a6, a7, a8, a9};
    MovieFilterRating rFilter;
    rFilter.setLowerBound(8.0);
    rFilter.setUpperBound(15.0);
    EXPECT_ANY_THROW(rFilter.filter(movies));
}

TEST(RatingFilterTests, LowerGreaterThanUpper) {
    vector<Movie> movies = {a1, a2, a3, a4, a5, a6, a7, a8, a9};
    MovieFilterRating rFilter;
    rFilter.setLowerBound(9.0);
    rFilter.setUpperBound(8.0);
    EXPECT_ANY_THROW(rFilter.filter(movies));
}
