#include "../header/Movie.h"
#include "../header/MovieFilter.h"
#include "../header/MovieList.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(MovieListAllocation, Construction) {
    MovieList newList;
    Movie *newPtr = new Movie("Garfield", 2025);
    newList.getMovieVector().push_back(newPtr);
    EXPECT_EQ(newList.getMovieVector().at(0)->getTitle(), "Garfield");
}

TEST(MovieListAllocation, YearFilterApplication) {
    MovieFilterYear yearFilter;
    yearFilter.setYear(2008);
    MovieList newList;
    newList.addMovie(new Movie("Casino Royale", 2006));
    newList.addMovie(new Movie("Quantum of Solace", 2008));
    newList.addMovie(new Movie("Skyfall", 2012));
    newList.addMovie(new Movie("Iron Man", 2008));
    newList.addMovie(new Movie("Role Models", 2008));
    newList.addMovie(new Movie("The Departed", 2006));
    yearFilter.filter(newList.getMovieVector());
    EXPECT_EQ(newList.getMovieVector().size(), 3);

}

TEST(MovieAllocation, YearRangeFilterApplication) {
    MovieFilterYearRange rangeFilter;
    rangeFilter.setLowerBound(2004);
    rangeFilter.setUpperBound(2010);
    MovieList newList;
    newList.addMovie(new Movie("Casino Royale", 2006));
    newList.addMovie(new Movie("Quantum of Solace", 2008));
    newList.addMovie(new Movie("Skyfall", 2012));
    newList.addMovie(new Movie("Iron Man", 2008));
    newList.addMovie(new Movie("Role Models", 2008));
    newList.addMovie(new Movie("The Departed", 2006));
    rangeFilter.filter(newList.getMovieVector());
    EXPECT_EQ(newList.getMovieVector().size(), 5);
}

TEST(MovieAllocation, StarFilterApplication) {
    MovieFilterStar starFilter;
    MovieList newList;
    newList.addMovie(new Movie("Barbie", 2023, "Comedy", 6.8, "Greta Gerwig", "Ryan Gosling"));
    newList.addMovie(new Movie("Forest Gump", 1994, "Drama", 8.8, "Robert Zemeckis", "Tom Hanks"));
    newList.addMovie(new Movie("BumbleBee", 2018, "Action", 6.7, "Travis Knight", "John Cena"));
    newList.addMovie(new Movie("Drive", 2011, "Action", 7.8, "Nicholas Winding Refn", "Ryan Gosling"));
    newList.addMovie(new Movie("Blade Runner 2049", 2017, "Mystery", 8.0, "Denis Villenueve", "Ryan Gosling"));
    starFilter.setStarNum(1);
    starFilter.setStarName("Ryan Gosling");

    starFilter.filter(newList.getMovieVector());
    EXPECT_EQ(newList.getMovieVector().size(), 3);
}

TEST(MovieAllocation, DirectorFilterApplication1) {
    MovieFilterDirector directorFilter;
    MovieList newList;
    newList.addMovie(new Movie("Barbi", 2023, "Comedy", 6.8, "Greta Gerwig", "Ryan Gosling"));
    newList.addMovie(new Movie("Forest Gum", 1994, "Drama", 8.8, "Robert Zemeckis", "Tom Hanks"));
    newList.addMovie(new Movie("BumbleBe", 2018, "Action", 6.7, "Travis Knight", "John Cena"));
    newList.addMovie(new Movie("Driv", 2011, "Action", 7.8, "Nicholas Winding Refn", "Ryan Gosling"));
    newList.addMovie(new Movie("Blade Runner 204", 2017, "Mystery", 8.0, "Denis Villenueve", "Ryan Gosling"));
    directorFilter.setDirectorName("Nicholas Winding Refn");

    directorFilter.filter(newList.getMovieVector());
    EXPECT_EQ(newList.getMovieVector().size(), 1);
}

TEST(MovieListAllocation, ClearMovieVector) {
    MovieList newList;
    newList.addMovie(new Movie("Movie 1", 2001));
    newList.addMovie(new Movie("Movie 2", 2002));
    newList.addMovie(new Movie("Movie 3", 2003));

    EXPECT_EQ(newList.getMovieVector().size(), 3);

    newList.clearMovies();

    EXPECT_EQ(newList.getMovieVector().size(), 0);
}