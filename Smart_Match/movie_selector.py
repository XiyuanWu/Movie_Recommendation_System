# from movie_display import MovieDisplay
from user_interact import UserInteract
import numpy as np
import pandas as pd

class MovieSelector:
    def __init__(self):
        self.user_interact = UserInteract()

    
    def generate_recommendations(self, user_interact: UserInteract):
        user_interact.load_movie()
        
        '''1. Find similar movie'''
        movies = pd.read_csv("Data/Smart_Match/movies.csv")
        ratings = pd.read_csv("Data/Smart_Match/ratings.csv")
        movie_database_df = pd.merge(ratings, movies)

        
        user_rating_df = pd.DataFrame(
            [(movie, movie_id, rating) for movie, (movie_id, rating) in user_interact.user_rating.items()],
            columns=["Movie_Name", "MovieID", "Rating"]
        )
        user_rating_df.insert(0, 'UserID', 'Target_User')

        combined_df = pd.concat([user_rating_df, movie_database_df])

        user_movie = combined_df.pivot_table(index="UserID", columns="Movie_Name", values="Rating")
        corrMatrix = user_movie.corr(method="pearson")

        '''2. Find target user movie they might interested'''
        target_user = user_movie.loc["Target_User"].dropna()

        name = target_user.index
        score = target_user.values

        simsMovie = corrMatrix[name].drop(index=name)
        prod = score * simsMovie
        movieList = prod.sum(axis=1)

        '''3. Make recommandation'''
        movieList = movieList.sort_values(ascending=False)
        movieList = movieList.index[0:5]
        movieList = movieList.values
        print(movieList)


      