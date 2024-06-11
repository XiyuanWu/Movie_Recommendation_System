#include "../header/Display.h"
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Display::~Display() {
//Destructor will be implemented later
}

void Display::primaryMenu(MovieList& movieList) {
    int choice;
    cout << "Welcome to the Movie Recommendation System!" << endl;
    cout << "How would you like the movie to be recommended?" << endl;
    cout << "1. Custom Features" << endl;
    cout << "2. Smart Match" << endl;
    cout << "The Custom Feature allows you to manually apply specific filters like genre or director to find movies," << endl;
    cout << "while Smart Match uses machine learning to recommend movies based on your personal ratings and preferences." << endl;
    cout << "Type your number as your choice: ";
    cin >> choice;

    if (choice == 1) {
        featureSelection(movieList);
    } else if (choice == 2) {
        smartMatch();
    } else {
        cout << "Invalid choice. Please restart the program and select a valid option." << endl;
    }
}

void Display::featureSelection(MovieList& movieList) {
    int choice;
    vector<MovieFilter*> filters;
    char addAnotherFilter;

    do {
        cout << "Please choose any or combination of the following features: " << endl
             << "1. Year" << endl
             << "2. Genre" << endl
             << "3. Rating" << endl
             << "4. Director" << endl
             << "5. Star" << endl
             << "6. Range of Years" << endl
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int year;
            cout << "Enter the year: ";
            cin >> year;
            MovieFilterYear *yFilter = new MovieFilterYear;
            yFilter->setYear(year);
            filters.push_back(yFilter);
            // RZ: it's temp fix as there's the option of filtering by year range
        } else if (choice == 2) {
            string genre;
            cout << "Enter the genre: ";
            cin >> genre;
            MovieFilterGenre *gFilter = new MovieFilterGenre;
            gFilter->setGenreName(genre);
            filters.push_back(gFilter);
            
        } else if (choice == 3) {
            double lowerBound, upperBound;
            cout << "Enter the lower bound of the rating range: ";
            cin >> lowerBound;
            cout << "Enter the upper bound of the rating range: ";
            cin >> upperBound;
            MovieFilterRating *rFilter = new MovieFilterRating;
            rFilter->setLowerBound(lowerBound);
            rFilter->setUpperBound(upperBound);
            filters.push_back(rFilter);
        }
        else if (choice == 4) {
            MovieFilterDirector* dFilter = new MovieFilterDirector;

            cout << "Enter a director: " ;
            cin.ignore();
            dFilter->setDirectorName(GetValidStr());
            if(dFilter->searchVector(dFilter->getDirectorName(), movieList.getMovieVector()) == -1){
                dFilter->setBreakNum(-1);
            }
            filters.push_back(dFilter);
        }
        else if (choice == 5) {
            MovieFilterStar* sFilter1 = new MovieFilterStar;

            sFilter1->setStarNum(1);
            cin.ignore();
            cout << "Enter the star name: " ;
            sFilter1->setStarName(GetValidStr());
            if(sFilter1->searchVector(sFilter1->getStarName(), movieList.getMovieVector()) == -1){
                sFilter1->setBreakNum(-1);
            }
            filters.push_back(sFilter1);

            cout << "Do you want to add a costar? " ; 
            if(GetValidYesOrNo() == "yes"){
                MovieFilterStar* sFilter2 = new MovieFilterStar;

                sFilter2->setStarNum(2);
                cout << "Enter the star name: " << endl;
                cin.ignore();
                sFilter2->setStarName(GetValidStr());
                if(sFilter2->searchVector(sFilter2->getStarName(), movieList.getMovieVector()) == -1){
                    sFilter2->setBreakNum(-1);
                }
                filters.push_back(sFilter2);
            }

        }
        else if (choice == 6) {
            int lowerBound, upperBound;
            cout << "Enter the lower bound of the year range: ";
            cin >> lowerBound;
            cout << "Enter the upper bound of the year range: ";
            cin >> upperBound;
            MovieFilterYearRange *yrFilter = new MovieFilterYearRange;
            yrFilter->setLowerBound(lowerBound);
            yrFilter->setUpperBound(upperBound);
            filters.push_back(yrFilter);
        }
        else {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        cout << "Do you want to apply another filter? (Y/N): ";
        cin >> addAnotherFilter;
    } while ((addAnotherFilter == 'Y' || addAnotherFilter == 'y') && filters.size() < 6);

    for (auto& filter : filters) {
        if(filter->getBreakNum() != -1){
            filter->filter(movieList.getMovieVector());
        }
        else{
            cout << endl << "Bad Filter. Stops filtering. Continue the display succesfully filtered movies. " << endl << endl;
            break;
        }
    }

    //Then deallocate filters
    for (auto& filter : filters) {
        delete filter;
    }
    filters.clear();
    
}

void Display::smartMatch() {
    // Call the Python script
    system("python3 ./Smart_Match/main.py");
    exit(0);
}

void Display::displayRecResult(const vector<Movie>& movieList) {
    vector<Movie> recommendedMovies = movieList;
    // Sort movies by rating in descending order
    sort(recommendedMovies.begin(), recommendedMovies.end(), [](const Movie& a, const Movie& b) {
        return a.getRating() > b.getRating();
    });

    if (recommendedMovies.size() > 6) {
        recommendedMovies.resize(6);
    }

    cout << "Recommended Movies:" << endl;
    for (const Movie& movie : recommendedMovies) {
        cout << movie.getTitle() << " (" << movie.getYear() << ") - " << movie.getGenre() << " - Rating: " << movie.getRating()
             << " - Director: " << movie.getDirector() << " - Stars: " << movie.getStar1() << ", " << movie.getStar2() << endl;
    }

}

void Display::displayRecResult(MovieList& movieList) {
    // Sort movies by rating in descending order
    sort(movieList.getMovieVector().begin(), movieList.getMovieVector().end(), [](const Movie* a, const Movie* b) {
        return a->getRating() > b->getRating();
    });

    if (movieList.getMovieVector().size() == 0) {
        cout << "I apologize! None of our movies seem to match your criteria. Please run the program again with different parameters." << endl;
        exit(0);
    }
    const auto& movies = movieList.getMovieVector();
    size_t count = std::min(movies.size(), size_t(6)); // Ensure we only print up to 6 movies

    cout << "Recommended Movies:" << endl;
    for (size_t i = 0; i < count; ++i) {
        const Movie* movie = movies[i];
        std::cout << movie->getTitle() << " (" << movie->getYear() << ") - " << movie->getGenre()
                << " - Rating: " << movie->getRating() << " - Director: " << movie->getDirector()
                << " - Stars: " << movie->getStar1() << ", " << movie->getStar2() << std::endl;
    }
}

string Display::GetValidYesOrNo(){
    bool isValid = true;
    string yesorNo;

    do{
        if(isValid == false){ cout << "Invalid input. Please try again: "; }
        cin >> yesorNo;

        isValid = validYesOrNo(yesorNo);

        cin.clear();
        cout << endl;
    } while(isValid == false);

    return yesorNo;
}

bool Display::validYesOrNo(string& input){
    bool isValid = false;
    string rewriteInput;

    for(int i = 0; i < input.size(); ++i){
        rewriteInput.push_back(tolower(input.at(i)));
    }


    if(rewriteInput == "yes"){        // they could put YES or yEs or other combo... Same with no
        isValid = true;
    }
    else if(rewriteInput == "no"){
        isValid = true;
    }

    input = rewriteInput;

    return isValid;
}

string Display::GetValidStr(){
    string name;
    cin.clear();
    getline(cin, name);
    while(validStringInput(name) == -1){
        cout << "Invalid input. Please try again: " << endl;
        cin.clear();
        cin.clear();
        getline(cin, name);
    }
    cin.clear();

    return name; 
}

// NOTE: Doesn't accept " John Hans " or any string with space in first or last char
bool Display::validStringInput(const string &input){    // returns T if not a letter (except space)
    bool isString = true;
    if(isspace(input.at(0)) || isspace(input.at(input.size() - 1))){
        isString = false;
    }
    else{
        for(int i = 0; i < input.size(); ++i){
            if(!isalpha(input.at(i))){
                if(!isspace(input.at(i))){
                    isString = false;
                    break; 
                }
            }
        }
    }

    return isString;
}

// We will  simply return empty vector if input is not found on database.
// If a filter fails, we will put a message in display (by comparing the length of copy before filter and the filter result vector) and then display what we have...
