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

    films.push_back(Film("Django", "dramat", 8.5));
    films.push_back(Film("Good Fellas", "Dramat", 9.3));
    films.push_back(Film("American Sniper", "Wojenny", 7.8));
    films.push_back(Film("The Martian", "Sci-fi", 8.7));

    // Wyświetlenie informacji o wszystkich filmach
    std::cout << "Wszystkie filmy:" << std::endl;
    for (const auto& film : films) {
        film.PrintInfo();
    }

    // Posortowanie filmów według oceny
    std::sort(films.begin(), films.end());

    // Wyświetlenie posortowanych filmów
    std::cout << "\nFilmy ułożone względem ocen:" << std::endl;
    for (const auto& film : films) {
        film.PrintInfo();
    }

    return 0;
}