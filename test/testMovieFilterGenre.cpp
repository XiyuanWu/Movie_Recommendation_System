#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

Movie g1("Inception", 2010, "Sci-Fi", 8.8, "Christopher Nolan", "Leonardo DiCaprio", "Joseph Gordon-Levitt");
Movie g2("The Dark Knight", 2008, "Action", 9.0, "Christopher Nolan", "Christian Bale", "Heath Ledger");
Movie g3("Pulp Fiction", 1994, "Crime", 8.9, "Quentin Tarantino", "John Travolta", "Uma Thurman");
Movie g4("The Godfather", 1972, "Crime", 9.2, "Francis Ford Coppola", "Marlon Brando", "Al Pacino");
Movie g5("Schindler's List", 1993, "Biography", 8.9, "Steven Spielberg", "Liam Neeson", "Ben Kingsley");
Movie g6("The Shawshank Redemption", 1994, "Drama", 9.3, "Frank Darabont", "Tim Robbins", "Morgan Freeman");
Movie g7("Fight Club", 1999, "Drama", 8.8, "David Fincher", "Brad Pitt", "Edward Norton");


// setGenreName
//Also indirectly tests toLower function which returns lower case string of user input
TEST(setGenreNameTest, validName) {
    string input = "Drama";

    MovieFilterGenre dramaFilter;
    dramaFilter.setGenreName(input);

    EXPECT_EQ(dramaFilter.getGenreName(), "drama");
}

// searchVector
TEST(searchVectorGenreTest, noResult) {
    vector<Movie> movies = {g1, g2, g3, g4, g5};
    string search = "Comedy";
    
    MovieFilterGenre comedyFilter;
    EXPECT_EQ(comedyFilter.searchVector(search, movies), -1);
}

TEST(searchVectorGenreTest, multipleInstances) {
    vector<Movie> movies = {g1, g2, g3, g4, g5, g6, g7};
    string search = "Drama";
    
    MovieFilterGenre dramaFilter;
    EXPECT_EQ(dramaFilter.searchVector(search, movies), 5); // First occurrence of "Drama" is at index 5
}

TEST(searchVectorGenreTest, oneInstance) {
    vector<Movie> movies = {g1, g2, g3, g4, g5};
    string search = "Sci-Fi";
    
    MovieFilterGenre sciFiFilter;
    EXPECT_EQ(sciFiFilter.searchVector(search, movies), 0); // First occurrence of "Sci-Fi" is at index 0
}

// gatherResult
TEST(gatherResultGenreTest, oneResultOnly) {
    vector<Movie> result = {g1, g2, g3, g4, g5};
    vector<Movie> movies = result;
    string search = "Sci-Fi";

    MovieFilterGenre sciFiFilter;
    sciFiFilter.gatherResult(result, sciFiFilter.searchVector(search, movies), search);

    vector<Movie> correctList = {g1};

    EXPECT_EQ(result.size(), correctList.size());

    if (result.size() == correctList.size()) {
        for (int i = 0; i < result.size(); ++i) {
            EXPECT_EQ(result.at(i).getTitle(), correctList.at(i).getTitle());
            EXPECT_EQ(result.at(i).getYear(), correctList.at(i).getYear());
            EXPECT_EQ(result.at(i).getGenre(), correctList.at(i).getGenre());
            EXPECT_EQ(result.at(i).getRating(), correctList.at(i).getRating());
            EXPECT_EQ(result.at(i).getDirector(), correctList.at(i).getDirector());
            EXPECT_EQ(result.at(i).getStar1(), correctList.at(i).getStar1());
            EXPECT_EQ(result.at(i).getStar2(), correctList.at(i).getStar2());
        }
    }
}

TEST(gatherResultGenreTest, multipleResults) {
    vector<Movie> result = {g1, g2, g3, g4, g5, g6, g7};
    vector<Movie> movies = result;
    string search = "Drama";

    MovieFilterGenre dramaFilter;
    dramaFilter.gatherResult(result, dramaFilter.searchVector(search, movies), search);
    
    vector<Movie> correctList = {g6, g7};

    EXPECT_EQ(result.size(), correctList.size());

    if (result.size() == correctList.size()) {
        for (int i = 0; i < result.size(); ++i) {
            EXPECT_EQ(result.at(i).getTitle(), correctList.at(i).getTitle());
            EXPECT_EQ(result.at(i).getYear(), correctList.at(i).getYear());
            EXPECT_EQ(result.at(i).getGenre(), correctList.at(i).getGenre());
            EXPECT_EQ(result.at(i).getRating(), correctList.at(i).getRating());
            EXPECT_EQ(result.at(i).getDirector(), correctList.at(i).getDirector());
            EXPECT_EQ(result.at(i).getStar1(), correctList.at(i).getStar1());
            EXPECT_EQ(result.at(i).getStar2(), correctList.at(i).getStar2());
        }
    }
}

TEST(gatherResultGenreTest, zeroResult) {
    vector<Movie> result = {g1, g2, g3, g4, g5, g6, g7};
    vector<Movie> movies = result;
    string search = "Comedy";

    MovieFilterGenre comedyFilter;
    comedyFilter.gatherResult(result, comedyFilter.searchVector(search, movies), search);

    EXPECT_EQ(result.size(), 0);
}
