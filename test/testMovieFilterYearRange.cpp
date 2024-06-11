#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

using namespace testing;

Movie f1("The Fast and the Furious", 2001);
Movie f2("2 Fast 2 Furious", 2003);
Movie f3("Tokyo Drift", 2006);
Movie f4("Fast Five", 2011);
Movie f5("Fast and Furious 6", 2013);

Movie f6("Furious 7", 2015);
Movie f7("The Fate of the Furious", 2017);
Movie f8("F9", 2021);
Movie f9("Fast X", 2023);

TEST(YearFilterRangeTests, ValidRange) {
    vector<Movie> movies = {f1, f2, f3, f4, f5, f6, f7, f8, f9};
    MovieFilterYearRange rFilter;
    rFilter.setLowerBound(2005);
    rFilter.setUpperBound(2015);
    rFilter.filter(movies);
    EXPECT_THAT(movies, ElementsAre(f3,f4,f5,f6));
}

TEST(YearFilterRangeTests, BadLowerBound) {
    vector<Movie> movies = {f1, f2, f3, f4, f5, f6, f7, f8, f9};
    MovieFilterYearRange rFilter;
    rFilter.setLowerBound(1655);
    rFilter.setUpperBound(2012);
    EXPECT_ANY_THROW(rFilter.filter(movies));
}

TEST(YearFilterRangeTests, BadUpperBound) {
    vector<Movie> movies = {f1, f2, f3, f4, f5, f6, f7, f8, f9};
    MovieFilterYearRange rFilter;
    rFilter.setLowerBound(2013);
    rFilter.setUpperBound(2077);
    EXPECT_ANY_THROW(rFilter.filter(movies));
}