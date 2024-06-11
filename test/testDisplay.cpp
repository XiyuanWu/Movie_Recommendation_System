#include "../header/Display.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include <string>

TEST(validYesOrNo, normalInput){
    Display response1 = Display();

    string inputOne = "yes";
    string inputTwo = "no";

    EXPECT_TRUE(response1.validYesOrNo(inputOne) == 1);
    EXPECT_TRUE(response1.validYesOrNo(inputTwo) == 1);
}

TEST(validYesOrNo, caseInput){
    Display response1 = Display();

    string inputOne = "yES";
    string inputTwo = "NO";

    EXPECT_TRUE(response1.validYesOrNo(inputOne) == 1);
    EXPECT_TRUE(response1.validYesOrNo(inputTwo) == 1);
}

TEST(validYesOrNo, nonStandardInput){
    Display response1 = Display();

    string inputOne = "Y";
    string inputTwo = "0";

    EXPECT_TRUE(response1.validYesOrNo(inputOne) == 0);
    EXPECT_TRUE(response1.validYesOrNo(inputTwo) == 0);
}

TEST(validYesOrNo, nonLetterInput){
    Display response1 = Display();

    string inputOne = "Y3s";
    string inputTwo = "N0";

    EXPECT_TRUE(response1.validYesOrNo(inputTwo) == 0);
}


TEST(validStringInput, numberInput){
    Display response1 = Display();
    
    string input = "33 Vesta";

    EXPECT_TRUE(response1.validStringInput(input) == 0);
}

TEST(validStringInput, stringInput){
    Display response1 = Display();

    string input = "Savior Jane";

    EXPECT_TRUE(response1.validStringInput(input) == 1);
}

TEST(validStringInput, specialCharacterInput){
    Display response1 = Display();

    string input = "Savi%or Jane!@#";

    EXPECT_TRUE(response1.validStringInput(input) == 0);
}

TEST(validStringInput, weirdSpaceInput){
    Display response1 = Display();

    string inputOne = " Savior Jane";
    string inputTwo = "Savior Jane ";

    EXPECT_TRUE(response1.validStringInput(inputOne) == 0);
    EXPECT_TRUE(response1.validStringInput(inputTwo) == 0);
}

//Tests for void Display::displayRecResult(MovieList& movieList)
//Test output with less than 6 movies
TEST(DisplayMovieListRecResult_MovieList, LessThanSixMovies) {
    Display display;
    MovieList movieList;

    movieList.addMovie(new Movie("Movie A", 2001, "Drama", 9.0, "Director A", "Star A1", "Star A2"));
    movieList.addMovie(new Movie("Movie B", 2002, "Action", 8.5, "Director B", "Star B1", "Star B2"));
    movieList.addMovie(new Movie("Movie C", 2003, "Comedy", 7.0, "Director C", "Star C1", "Star C2"));

    testing::internal::CaptureStdout();
    display.displayRecResult(movieList);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Recommended Movies:") != string::npos);
    EXPECT_TRUE(output.find("Movie A (2001) - Drama - Rating: 9 - Director: Director A - Stars: Star A1, Star A2") != string::npos);
    EXPECT_TRUE(output.find("Movie B (2002) - Action - Rating: 8.5 - Director: Director B - Stars: Star B1, Star B2") != string::npos);
    EXPECT_TRUE(output.find("Movie C (2003) - Comedy - Rating: 7 - Director: Director C - Stars: Star C1, Star C2") != string::npos);

    // Clean up
    for (Movie* movie : movieList.getMovieVector()) {
        delete movie;
    }
    movieList.getMovieVector().clear();

}

// Test for output when there are more than 6 movies
TEST(DisplayMovieListRecResult_MovieList, MoreThanSixMovies) {
    Display display;
    MovieList movieList;

    movieList.addMovie(new Movie("Movie A", 2001, "Drama", 9.0, "Director A", "Star A1", "Star A2"));
    movieList.addMovie(new Movie("Movie B", 2002, "Action", 8.5, "Director B", "Star B1", "Star B2"));
    movieList.addMovie(new Movie("Movie C", 2003, "Comedy", 7.0, "Director C", "Star C1", "Star C2"));
    movieList.addMovie(new Movie("Movie D", 2004, "Horror", 6.5, "Director D", "Star D1", "Star D2"));
    movieList.addMovie(new Movie("Movie E", 2005, "Sci-Fi", 8.0, "Director E", "Star E1", "Star E2"));
    movieList.addMovie(new Movie("Movie F", 2006, "Romance", 7.5, "Director F", "Star F1", "Star F2"));
    movieList.addMovie(new Movie("Movie G", 2007, "Fantasy", 8.2, "Director G", "Star G1", "Star G2"));

    testing::internal::CaptureStdout();
    display.displayRecResult(movieList);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Recommended Movies:") != string::npos);
    EXPECT_TRUE(output.find("Movie A (2001) - Drama - Rating: 9 - Director: Director A - Stars: Star A1, Star A2") != string::npos);
    EXPECT_TRUE(output.find("Movie B (2002) - Action - Rating: 8.5 - Director: Director B - Stars: Star B1, Star B2") != string::npos);
    EXPECT_TRUE(output.find("Movie G (2007) - Fantasy - Rating: 8.2 - Director: Director G - Stars: Star G1, Star G2") != string::npos);
    EXPECT_TRUE(output.find("Movie E (2005) - Sci-Fi - Rating: 8 - Director: Director E - Stars: Star E1, Star E2") != string::npos);
    EXPECT_TRUE(output.find("Movie F (2006) - Romance - Rating: 7.5 - Director: Director F - Stars: Star F1, Star F2") != string::npos);
    EXPECT_TRUE(output.find("Movie C (2003) - Comedy - Rating: 7 - Director: Director C - Stars: Star C1, Star C2") != string::npos);

    // Checks that only the first 6 movies are printed
    EXPECT_EQ(count(output.begin(), output.end(), '\n'), 7); // 1 for "Recommended Movies:" + 6 movies

    // Clean up
    for (Movie* movie : movieList.getMovieVector()) {
        delete movie;
    }
    movieList.getMovieVector().clear();

}

// Tests for void Display::displayRecResult(const vector<Movie>& movieList)
//Test for less than six movies
TEST(DisplayMovieListRecResult_Vector, LessThanSixMovies) {
    Display display;
    vector<Movie> movieList;

    movieList.push_back(Movie("Movie A", 2001, "Drama", 9.0, "Director A", "Star A1", "Star A2"));
    movieList.push_back(Movie("Movie B", 2002, "Action", 8.5, "Director B", "Star B1", "Star B2"));
    movieList.push_back(Movie("Movie C", 2003, "Comedy", 7.0, "Director C", "Star C1", "Star C2"));

    testing::internal::CaptureStdout();
    display.displayRecResult(movieList);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Recommended Movies:") != string::npos);
    EXPECT_TRUE(output.find("Movie A (2001) - Drama - Rating: 9 - Director: Director A - Stars: Star A1, Star A2") != string::npos);
    EXPECT_TRUE(output.find("Movie B (2002) - Action - Rating: 8.5 - Director: Director B - Stars: Star B1, Star B2") != string::npos);
    EXPECT_TRUE(output.find("Movie C (2003) - Comedy - Rating: 7 - Director: Director C - Stars: Star C1, Star C2") != string::npos);
}

TEST(DisplayMovieListRecResult_vector, MoreThanSixMovies) {
    Display display;
    vector<Movie> movieList;

    movieList.push_back(Movie("Movie A", 2001, "Drama", 9.0, "Director A", "Star A1", "Star A2"));
    movieList.push_back(Movie("Movie B", 2002, "Action", 8.5, "Director B", "Star B1", "Star B2"));
    movieList.push_back(Movie("Movie C", 2003, "Comedy", 7.0, "Director C", "Star C1", "Star C2"));
    movieList.push_back(Movie("Movie D", 2004, "Horror", 6.5, "Director D", "Star D1", "Star D2"));
    movieList.push_back(Movie("Movie E", 2005, "Sci-Fi", 8.0, "Director E", "Star E1", "Star E2"));
    movieList.push_back(Movie("Movie F", 2006, "Romance", 7.5, "Director F", "Star F1", "Star F2"));
    movieList.push_back(Movie("Movie G", 2007, "Fantasy", 8.2, "Director G", "Star G1", "Star G2"));

    testing::internal::CaptureStdout();
    display.displayRecResult(movieList);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Recommended Movies:") != string::npos);
    EXPECT_TRUE(output.find("Movie A (2001) - Drama - Rating: 9 - Director: Director A - Stars: Star A1, Star A2") != string::npos);
    EXPECT_TRUE(output.find("Movie B (2002) - Action - Rating: 8.5 - Director: Director B - Stars: Star B1, Star B2") != string::npos);
    EXPECT_TRUE(output.find("Movie G (2007) - Fantasy - Rating: 8.2 - Director: Director G - Stars: Star G1, Star G2") != string::npos);
    EXPECT_TRUE(output.find("Movie E (2005) - Sci-Fi - Rating: 8 - Director: Director E - Stars: Star E1, Star E2") != string::npos);
    EXPECT_TRUE(output.find("Movie F (2006) - Romance - Rating: 7.5 - Director: Director F - Stars: Star F1, Star F2") != string::npos);
    EXPECT_TRUE(output.find("Movie C (2003) - Comedy - Rating: 7 - Director: Director C - Stars: Star C1, Star C2") != string::npos);

    EXPECT_EQ(count(output.begin(), output.end(), '\n'), 7); // 1 for "Recommended Movies:" + 6 movies
}