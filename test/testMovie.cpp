#include "../header/Movie.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

TEST(MovieConstructor, getterTest){
    Movie movie1 = Movie("Kung Fu Panda 4", 2024, "Animation", 6.3, "Mike Mitchell", "Jack Black", "Awkwafina");
    EXPECT_TRUE(movie1.getTitle() == "Kung Fu Panda 4");
    EXPECT_TRUE(movie1.getYear() == 2024);
    EXPECT_TRUE(movie1.getGenre() == "Animation");
    EXPECT_TRUE(movie1.getRating() == 6.3);
    EXPECT_TRUE(movie1.getDirector() == "Mike Mitchell");
    EXPECT_TRUE(movie1.getStar1() == "Jack Black");
    EXPECT_TRUE(movie1.getStar2() == "Awkwafina");
}

TEST(MovieConstructor, setterTest){
    Movie movie3 = Movie("Kung Fu Panda 4", 2024, "Animation", 6.3, "Mike Mitchell", "Jack Black", "Awkwafina");
    Movie movie2;
    movie2.setTitle("Kung Fu Panda 4");
    movie2.setYear(2024);
    movie2.setGenre("Animation");
    movie2.setRating(6.3);
    movie2.setDirector("Mike Mitchell");
    movie2.setStar1("Jack Black");
    movie2.setStar2("Awkwafina");
    EXPECT_TRUE(movie3.getTitle() == movie2.getTitle());
    EXPECT_TRUE(movie3.getYear() == movie2.getYear());
    EXPECT_TRUE(movie3.getGenre() == movie2.getGenre());
    EXPECT_TRUE(movie3.getRating() == movie2.getRating());
    EXPECT_TRUE(movie3.getDirector() == movie2.getDirector());
    EXPECT_TRUE(movie3.getStar1() == movie2.getStar1());
    EXPECT_TRUE(movie3.getStar2() == movie2.getStar2());
}