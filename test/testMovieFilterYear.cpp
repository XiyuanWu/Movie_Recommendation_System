#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

using namespace testing;

Movie m1("Cars", 2006);
Movie m2("Coco", 2017);
Movie m3("Toy Story", 1995);
Movie m4("Up", 2009);
Movie m5("Finding Nemo", 2003);

Movie m6("Flushed Away", 2006);
Movie m7("Over The Hedge", 2006);
Movie m8("Shark Tale", 2004);
Movie m9("Bee Movie", 2007);

TEST(YearFilterSingleInputTests, SmallSample) {
    vector<Movie> movies = {m1, m2, m3, m4, m5};
    MovieFilterYear yFilter;
    yFilter.setYear(2009);
    yFilter.filter(movies);
    EXPECT_THAT(movies, ElementsAre(m4));
}

TEST(YearFilterSingleInputTests, MultipleMatches) {
    vector<Movie> movies = {m1, m2, m3, m4, m5, m6, m7, m8, m9};
    MovieFilterYear yFilter;
    yFilter.setYear(2006);
    yFilter.filter(movies);
    EXPECT_THAT(movies, ElementsAre(m1,m6,m7));
}

TEST(YearFilterSingleInputTests, NotinSample) {
    vector<Movie> movies = {m1, m2, m3, m4, m5};
    MovieFilterYear yFilter;
    yFilter.setYear(2004);
    yFilter.filter(movies);
    EXPECT_THAT(movies, IsEmpty());
}

TEST(YearFilterSingleInputTests, NotValidYear) {
    vector<Movie> movies = {m1, m2, m3, m4, m5};
    MovieFilterYear yFilter;
    yFilter.setYear(1770);
    EXPECT_ANY_THROW(yFilter.filter(movies));
}


