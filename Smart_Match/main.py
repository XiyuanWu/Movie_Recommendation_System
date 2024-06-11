from movie_display import MovieDisplay
from user_interact import UserInteract
from movie_selector import MovieSelector

def main():

    movie_display = MovieDisplay()
    user_interact = UserInteract()
    movie_selector = MovieSelector()

    '''1. Dsiplay welcome prompt'''
    movie_display.display_instructions()
    user_interact.load_movie()


    user_input = input('Ready? Press anykey to display the movie list!')

    if user_input:
        print("Displaying movie list...\n")

    '''2. User enter 5 movie rating'''
    user_interact.select_random_movies()
    
    print('\n\033[34mPlease browse the movie list.\033[0m \033[32mWhen typing your rating, use a scale from 0.0 to 10.0 (e.g., enter 8.6).\033[0m \033[31mIf there are no more movies you have watched, press "r" to refresh the page.\033[0m')


    # Ask user for rating
    while True:
        if len(user_interact.user_rating) == 5:
            break
        else:
            ratings = user_interact.get_user_ratings()
            movie_display.display_user_rating(ratings)
            continue

    '''3. Ask user if want to enter more movie'''
    print("\033[34mYou already entered 5 movies.\033[0m Do you want to enter more?")
    choice = input("\033[33mPress 'q' to stop\033[0m, otherwise press any key to continue.")

    
    if choice.lower() != "q": 
        user_interact.select_random_movies()

        while True:
            more_ratings = user_interact.ask_for_more_ratings()
            if not more_ratings:
                break
            else:
                # user_interact.select_random_movies()
                movie_display.display_user_rating(more_ratings)
            

    # User rating summary
    print(f"Summary: You entered \033[1;34m{len(user_interact.user_rating)}\033[0m movie ratings:")
    movie_display.display_user_rating(user_interact)


    '''4. Display result'''
    print("Congrads! Here is movie recommendation for you:")
    print("Running...")
    movie_selector.generate_recommendations(user_interact)
    print("Done. Enjoy!")


if __name__ == "__main__":
    main()



