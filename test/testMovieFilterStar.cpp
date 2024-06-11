#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

Movie m01("Cars", 2006, "", 0.0, "", "Josh Brown", "David Ozen");
Movie m02("Coco", 2017, "", 0.0, "", "Josh Brown", "Gave Gastby");
Movie m03("Toy Story", 1995, "", 0.0, "", "David Ozen", "Bill Nye");
Movie m04("Up", 1995, "", 0.0, "", "Kelly Allen", "Bill Nye");
Movie m05("Finding Nemo", 2003, "", 0.0, "", "Kelly Allen", "Guy Gardener");
Movie m06("Finding Nemo 2", 2007, "", 0.0, "", "Kelly Allen", "Josh Brown");

// setter getter starName test
TEST(setterGetterStarNameTest, validName){
    string input = "Josh Brown";
    MovieFilterStar JoshBrownFilter = MovieFilterStar();

    JoshBrownFilter.setStarName(input);

    EXPECT_TRUE(JoshBrownFilter.getStarName() == input);
}

// setter getter starNum test
TEST(setterGetterStarNumTest, validNum){
    MovieFilterStar JoshBrownFilter = MovieFilterStar();
    JoshBrownFilter.setStarNum(2);

    EXPECT_TRUE(JoshBrownFilter.getStarNum() == 2);
}

// searchVector
TEST(searchVectorTest, noResult){
    vector<Movie> movies = {m01, m02, m03, m04, m05};
    string search = "Jeremy Olsen";
    
    MovieFilterStar JeremyOlsenFilter = MovieFilterStar();
    JeremyOlsenFilter.setStarNum(1);

    EXPECT_TRUE(JeremyOlsenFilter.searchVector(search, movies) == -1);

    JeremyOlsenFilter.setStarNum(2);
    EXPECT_TRUE(JeremyOlsenFilter.searchVector(search, movies) == -1);
}

TEST(searchVectorTest, multipleInstances){
    vector<Movie> movies = {m01, m02, m03, m04, m05, m06};
    string search = "Josh Brown";
    
    MovieFilterStar JoshBrownFilter = MovieFilterStar();
    JoshBrownFilter.setStarNum(1);

    EXPECT_TRUE(JoshBrownFilter.searchVector(search, movies) == 0);

    JoshBrownFilter.setStarNum(2);
    EXPECT_TRUE(JoshBrownFilter.searchVector(search, movies) == 5);
}

TEST(searchVectorTest, oneInstance){
    vector<Movie> movies = {m01, m02, m03, m04, m05};
    string search = "Guy Gardener";
    
    MovieFilterStar GuyGardnerFilter = MovieFilterStar();
    GuyGardnerFilter.setStarNum(2);

    EXPECT_TRUE(GuyGardnerFilter.searchVector(search, movies) == 4);
}

// gatherResult
TEST(gatherResultTest, oneResultStat2Only){
    vector<Movie> result = {m01, m02, m03, m04, m05};
    vector<Movie> movies = result;
    string search = "Guy Gardener";

    MovieFilterStar GuyGardnerFilter = MovieFilterStar();
    GuyGardnerFilter.setStarNum(2);
    GuyGardnerFilter.gatherResult(result, GuyGardnerFilter.searchVector(search, movies), search);

    vector<Movie> correctList = {m05};

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

TEST(gatherResultTest, multipleResultStar1Only){
    vector<Movie> result = {m01, m02, m03, m04, m05, m06};
    vector<Movie> movies = result;
    string search = "Josh Brown";

    MovieFilterStar JoshBrownFilter = MovieFilterStar();
    JoshBrownFilter.setStarNum(1);
    JoshBrownFilter.gatherResult(result, JoshBrownFilter.searchVector(search, movies), search);
    
    vector<Movie> correctList = {m01, m02};

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

TEST(gatherResultTest, zeroResult){
    vector<Movie> result = {m01, m02, m03, m04, m05, m06};
    vector<Movie> movies = result;
    string search = "Josh Brow";

    MovieFilterStar JoshBrowFilter = MovieFilterStar();
    JoshBrowFilter.setStarNum(1);
    JoshBrowFilter.gatherResult(result, JoshBrowFilter.searchVector(search, movies), search);

    EXPECT_TRUE(result.size() == 0);
}