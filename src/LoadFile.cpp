#include "../header/Loadfile.h"

bool LoadFile::isCSVFileType(const string &fileName) {
    std::string fileExtension = ".csv";
    if (fileName.size() >= fileExtension.size() && 
        fileName.compare(fileName.size() - fileExtension.size(), fileExtension.size(), fileExtension) == 0) {
        return true;
    }
    return false;
}

void LoadFile::loadMoviesFromFile(MovieList &movieList, const string &fileName) {
    if (!(isCSVFileType(fileName))) {
        throw runtime_error("Not a Valid FileType.");
    }

    ifstream csvFile(fileName);
    if (!(csvFile.is_open())) {
        throw runtime_error("Error opening file.");
    }

    std::string line;

    getline(csvFile, line); // Need to ignore the first line.

    while (getline(csvFile, line)) {
        stringstream lineStream(line);
        std::string indexStr, title, yearStr, genre, ratingStr, director, star1, star2;

        if (std::getline(lineStream, indexStr, ',') &&
            std::getline(lineStream, title, ',') &&
            std::getline(lineStream, yearStr, ',') &&
            std::getline(lineStream, genre, ',') &&
            std::getline(lineStream, ratingStr, ',') &&
            std::getline(lineStream, director, ',') &&
            std::getline(lineStream, star1, ',') &&
            std::getline(lineStream, star2, ',')) {

            int year = std::stoi(yearStr);
            double rating = std::stod(ratingStr);

            Movie *newMovie = new Movie(title, year, genre, rating, director, star1, star2);
            movieList.addMovie(newMovie);
        }

        else {
            throw runtime_error("Something went wrong while reading the file. Please check that it is formatted correctly.");
        }
    }

    csvFile.close();

}