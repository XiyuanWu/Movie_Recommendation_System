#include "../header/Display.h"
#include "../header/Loadfile.h"

int main () {
    // Load databse in
    MovieList movieList;
    LoadFile lf;
    lf.loadMoviesFromFile(movieList, "Data/imdb_top_1000_FIXED.csv");
    //Setup the display
    Display display;
    display.primaryMenu(movieList);
    display.displayRecResult(movieList);
}
