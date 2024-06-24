#include <iostream>
#include <vector>
#include <algorithm>

class Film {
private:
    std::string name;
    std::string genre;
    double rating;

public:
    Film(const std::string& filmName, const std::string& filmGenre, double filmRating)
        : name(filmName), genre(filmGenre), rating(filmRating) {}

    std::string GetName() const {
        return name;
    }

    std::string GetGenre() const {
        return genre;
    }

    double GetRating() const {
        return rating;
    }

    void PrintInfo() const {
        std::cout << "Nazwa filmu: " << name << ", Gatunek: " << genre << ", Ocena: " << rating << std::endl;
    }

    bool operator<(const Film& other) const {
        return rating < other.rating;
    }
};

int main() {
    std::vector<Film> films;

    std::string filmName, filmGenre;
    double filmRating;

    std::cout << "Dodawanie nowych filmow. Wpisz 'stop', aby zakonczyc.\n";
    while (true) {
        std::cout << "Podaj nazwe filmu: ";
        std::getline(std::cin, filmName);

        if (filmName == "stop")
            break;

        std::cout << "Podaj gatunek filmu: ";
        std::getline(std::cin, filmGenre);

        std::cout << "Podaj ocene filmu: ";
        std::cin >> filmRating;
        std::cin.ignore(); 

        films.push_back(Film(filmName, filmGenre, filmRating));

        std::cout << "Film dodany!\n";
    }

    std::cout << "\nWszystkie filmy:" << std::endl;
    for (const auto& film : films) {
        film.PrintInfo();
    }

    std::sort(films.begin(), films.end());

    std::cout << "\nFilmy ulozone wzgledem ocen:" << std::endl;
    for (const auto& film : films) {
        film.PrintInfo();
    }

    return 0;
}
//random_push
