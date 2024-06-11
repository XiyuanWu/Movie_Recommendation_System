import pandas as pd

class UserInteract:
    def __init__(self):
        self.movie = pd.DataFrame()
        self.movie2 = pd.DataFrame()
        self.movie_with_user = pd.DataFrame()
        self.random_movie = pd.DataFrame()
        self.user_rating = {}

    def load_movie(self):
        self.movie = pd.read_csv("Data/Smart_Match/movies.csv", usecols=["MovieID", "Movie_Name"])

    def select_random_movies(self):

        self.random_movie = pd.DataFrame()  
        self.random_movie = self.movie.sample(n=10).reset_index(drop=True)

        print("\nHere are 10 random movie for you to rate:")
        for idx, row in self.random_movie.iterrows():
            print(f"{idx + 1}. {row['Movie_Name']}")

        return self.random_movie
    
    def get_user_ratings(self):

        while True:

            index = input("\033[34mPlease enter the movie's index that you already watched ('r' for refresh).\033[0m \033[32mYou can modify the rating by typing the same index and providing a new rating.\033[0m")

            if index.lower() == 'r':  
                self.select_random_movies()
                continue
            
            elif index.isdigit():
                index = int(index) - 1

                if 0 <= index < 10:
                    movie2 = self.random_movie.iloc[index]
                    movie_title = movie2["Movie_Name"]
                    movie_id = movie2["MovieID"]
                    
                    while True:
                        rating = input(f"Rate \033[32m{movie_title}\033[0m (0.0 to 10.0, or 's' to skip): ").strip()
                        if rating.lower() == 's':
                            print("You choose to skip this movie.")
                            break
                        try:
                            rating = float(rating)
                            if 0.0 <= rating <= 10.0:
                                self.user_rating[movie_title] = (movie_id, rating)
                                print("✅ Rating recorded. ")
                                return self
                                # break
                            else:
                                print("❌ Please enter a valid rating between 0.0 and 10.0.")
                        except ValueError:
                            print("❌ Invalid input. Please enter a number or 's' to skip.")
                
                else:
                    print("❌ Invalid index. Please enter a valid index number.")
            else:
                print("❌ Invalid input. Please enter a numeric index.")


    def ask_for_more_ratings(self):
        
        print()
        print("\033[34mYou choose to enter more movies.\033[0m")
        print("\033[32mRemember, there is no limit for you to enter movie ratings.\033[0m")

        while True:

            print()
            index = input("\033[34mPlease enter the movie index.\033[0m Press '\033[33mr\033[0m' for refresh, '\033[33mq\033[0m' when finished adding movies. \033[32mYou can modify the rating by typing the same index and providing a new rating.\033[0m")

            
            if index.lower() == 'r':  
                self.select_random_movies()
                continue

            elif index.lower() == 'q':
                print("Finished add movie.")
                return False
            
            elif index.isdigit():
                index = int(index) - 1

                if 0 <= index < 10:
                    movie = self.random_movie.iloc[index]
                    movie_title = movie["Movie_Name"]
                    movie_id = movie["MovieID"]
                    
                    while True:
                        rating = input(f"Rate \033[32m{movie_title}\033[0m (0.0 to 10.0, or 's' to skip): ").strip()
                        if rating.lower() == 's':
                            print("You choose to skip this movie.")
                            break
                        try:
                            rating = float(rating)
                            if 0.0 <= rating <= 10.0:
                                self.user_rating[movie_title] = (movie_id, rating)
                                print("✅ Rating recorded.")
                                return self
                            else:
                                print("❌ Please enter a valid rating between 0.0 and 10.0.")
                        except ValueError:
                            print("❌ Invalid input. Please enter a number or 's' to skip.")
                
                else:
                    print("❌ Invalid index. Please enter a valid index number.")
            else:
                print("❌ Invalid input. Please enter a numeric index.")        