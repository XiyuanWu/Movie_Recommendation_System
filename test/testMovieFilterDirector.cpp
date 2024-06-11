#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

Movie m001("Cars", 2006, "", 0.0, "Josh Brown", "", "");
Movie m002("Coco", 2017, "", 0.0,  "Josh Zoey", "", "");
Movie m003("Toy Story", 1995, "", 0.0, "David Ozen", "", "");
Movie m004("Up", 1995, "", 0.0, "Kelly Allen", "", "");
Movie m005("Finding Nemo", 2003, "", 0.0, "Kelly Allen", "", "");
Movie m006("Finding Nemo 2", 2007, "", 0.0, "Kelly Allen", "", "");


// setDirectorName
TEST(setDirectorNameTest, validName){
    string input = "Josh Brown";

    MovieFilterDirector JoshBrownFilter = MovieFilterDirector();
    JoshBrownFilter.setDirectorName(input);

    EXPECT_TRUE(JoshBrownFilter.getDirectorName() == input);
}

// searchVector
TEST(searchVectorDirectorTest, noResult){
    vector<Movie> movies = {m001, m002, m003, m004, m005};
    string search = "Jeremy Olsen";
    
    MovieFilterDirector JeremyOlsenFilter = MovieFilterDirector();

    EXPECT_TRUE(JeremyOlsenFilter.searchVector(search, movies) == -1);
}

TEST(searchVectorDirectorTest, multipleInstances){
    vector<Movie> movies = {m001, m002, m003, m004, m005, m006};
    string search = "Kelly Allen";
    
    MovieFilterDirector KellyAllenFilter = MovieFilterDirector();

    EXPECT_TRUE(KellyAllenFilter.searchVector(search, movies) == 3);
}

TEST(searchVectorDirectorTest, oneInstance){
    vector<Movie> movies = {m001, m002, m003, m004, m005};
    string search = "Josh Brown";
    
    MovieFilterDirector JoshBrownFilter = MovieFilterDirector();

    EXPECT_TRUE(JoshBrownFilter.searchVector(search, movies) == 0);
}

// gatherResult
TEST(gatherResultDirectorTest, oneResultOnly){
    vector<Movie> result = {m001, m002, m003, m004, m005};
    vector<Movie> movies = result;
    string search = "Josh Brown";

    MovieFilterDirector JoshBrownFilter = MovieFilterDirector();
    JoshBrownFilter.gatherResult(result, JoshBrownFilter.searchVector(search, movies), search);

    vector<Movie> correctList = {m001};

    EXPECT_TRUE(result.size() == correctList.size());

    if(result.size() == correctList.size()){
        for(int i = 0; i < result.size(); ++i){
            EXPECT_TRUE(result.at(i).getTitle() == correctList.at(i).getTitle());
            EXPECT_TRUE(result.at(i).getYear() == correctList.at(i).getYear());
            EXPECT_TRUE(result.at(i).getGenre() == correctList.at(i).getGenre());
            EXPECT_TRUE(result.at(i).getRating() == correctList.at(i).getRating());
            EXPECT_TRUE(result.at(i).getDirector() == correctList.at(i).getDirector());
            EXPECT_TRUE(result.at(i).getStar1() == correctList.at(i).getStar1());
            EXPECT_TRUE(result.at(i).getStar2() == correctList.at(i).getStar2());
        }
    }
}

TEST(gatherResultDirectorTest, multipleResultOnly){
    vector<Movie> result = {m001, m002, m003, m004, m005, m006};
    vector<Movie> movies = result;
    string search = "Kelly Allen";

    MovieFilterDirector KellyAllenFilter = MovieFilterDirector();
    KellyAllenFilter.gatherResult(result, KellyAllenFilter.searchVector(search, movies), search);
    
    vector<Movie> correctList = {m004, m005, m006};

    EXPECT_TRUE(result.size() == correctList.size());

    if(result.size() == correctList.size()){
        for(int i = 0; i < result.size(); ++i){
            EXPECT_TRUE(result.at(i).getTitle() == correctList.at(i).getTitle());
            EXPECT_TRUE(result.at(i).getYear() == correctList.at(i).getYear());
            EXPECT_TRUE(result.at(i).getGenre() == correctList.at(i).getGenre());
            EXPECT_TRUE(result.at(i).getRating() == correctList.at(i).getRating());
            EXPECT_TRUE(result.at(i).getDirector() == correctList.at(i).getDirector());
            EXPECT_TRUE(result.at(i).getStar1() == correctList.at(i).getStar1());
            EXPECT_TRUE(result.at(i).getStar2() == correctList.at(i).getStar2());
        }
    }
}

TEST(gatherResultDirectorTest, zeroResult){
    vector<Movie> result = {m001, m002, m003, m004, m005, m006};
    vector<Movie> movies = result;
    string search = "Kelly Alle";

    MovieFilterDirector KellyAlleFilter = MovieFilterDirector();
    KellyAlleFilter.gatherResult(result, KellyAlleFilter.searchVector(search, movies), search);

    EXPECT_TRUE(result.size() == 0);

}