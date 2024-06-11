#include "../header/Loadfile.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(LoadFileTests, smallCSV) {
    string filePath = "test/loadFileTestCSVs/test1.csv";
    MovieList newList;
    LoadFile lfObject;
    lfObject.loadMoviesFromFile(newList, filePath);
    EXPECT_EQ(newList.getMovieVector().size(), 11);
    EXPECT_EQ(newList.getMovieVector().at(0)->getTitle(), "The Shawshank Redemption");
    EXPECT_EQ(newList.getMovieVector().at(0)->getYear(), 1994);
    EXPECT_EQ(newList.getMovieVector().at(0)->getGenre(), "Drama");
    EXPECT_EQ(newList.getMovieVector().at(0)->getRating(), 9.3);
    EXPECT_EQ(newList.getMovieVector().at(0)->getDirector(), "Frank Darabont");
    EXPECT_EQ(newList.getMovieVector().at(0)->getStar1(), "Tim Robbins");
    EXPECT_EQ(newList.getMovieVector().at(0)->getStar2(), "Morgan Freeman");
}

TEST(LoadFileTests, fullCSV) {
    string filePath = "test/loadFileTestCSVs/imdb_top_1000_FIXED.csv";
    MovieList newList;
    LoadFile lfObject;
    lfObject.loadMoviesFromFile(newList, filePath);
    EXPECT_EQ(newList.getMovieVector().size(), 1000);
    EXPECT_EQ(newList.getMovieVector().at(999)->getTitle(), "The 39 Steps");
    EXPECT_EQ(newList.getMovieVector().at(999)->getYear(), 1935);
    EXPECT_EQ(newList.getMovieVector().at(999)->getGenre(), "Crime");
    EXPECT_EQ(newList.getMovieVector().at(999)->getRating(), 7.6);
    EXPECT_EQ(newList.getMovieVector().at(999)->getDirector(), "Alfred Hitchcock");
    EXPECT_EQ(newList.getMovieVector().at(999)->getStar1(), "Robert Donat");
    EXPECT_EQ(newList.getMovieVector().at(999)->getStar2(), "Madeleine Carroll");
}

TEST(LoadFileTests, IncorrectFile) {
    string filePath = "test/loadFileTestCSVs/nothing.txt";
    LoadFile lfObject;
    EXPECT_FALSE(lfObject.isCSVFileType(filePath));
}

TEST(LoadFileTests, BadFileFormat) {
    string filePath = "test/loadFileTestCSVs/test2.csv";
    LoadFile lfObject;
    MovieList newList;
    EXPECT_ANY_THROW(lfObject.loadMoviesFromFile(newList, filePath));
}