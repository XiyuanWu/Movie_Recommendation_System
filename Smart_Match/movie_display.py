# from movie_selector import MovieSelector
from user_interact import UserInteract
import pandas as pd

class MovieDisplay:


    '''User Interface'''
    def display_instructions(self):
        print("\033[34mWelcome to \033[32mSmart Match!\033[0m")
        print("\033[36mUnder this mode, we will recommend movies based on your watch history to find your best match.\033[0m")
        print("You need to provide ratings for at least 5 movies, but 15-30 ratings are better.")
        print("After you provide this information, we will recommend the best movies for you!")
        print()
        print("\033[35mFirst, a list of movies will be displayed, and you need to choose the movies you have already watched.\033[0m")
        print("If you see any movies you have watched, type the corresponding number to provide your rating.")
        print('If there are no more movies you have watched, you can refresh the page.')
        print("\033[33mYou can do this as many times as you want; there are no limits until we get ratings for at least 5 movies.\033[0m")
        print()


    '''Display function'''
    def display_movie(self, user_interact: UserInteract):

        if user_interact.movie.empty:
            print("No movies are loaded.")
        else:
            print("List of all movies:")

        for index, row in user_interact.user_interact.movie.iterrows():
            print(f"{index + 1}. {row['Movie_Name']} ({row['Rating']})")  

    def display_random_movie(self, user_interact: UserInteract):

        if user_interact.random_movie.empty:
            print("No movies are loaded.")
        else:
            print("List of movies:")

        for index, row in user_interact.random_movie.iterrows():
            print(f"{index + 1}. {row['Movie_Name']} ({row['Rating']})")  
        return

    def display_user_rating(self, user_interact: UserInteract):

        if not user_interact.user_rating:
            print("No ratings have been entered yet.")
        else:
            index = 1
            print()
            print("\033[31m" + "Your Ratings:" + "\033[0m")
            for movie, rating in user_interact.user_rating.items():
                print(f"{index}. {movie}: {rating}")
                index += 1
            print()
        