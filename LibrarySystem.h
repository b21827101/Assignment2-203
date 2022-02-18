
#ifndef UNTITLED1_LIBRARYSYSTEM_H
#define UNTITLED1_LIBRARYSYSTEM_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();

    void deleteMovie(const int movieId);
    void addMovie(const int movieId, const string movieTitle, const int year);

    void addUser(const int userId, const string userName);
    void deleteUser(const int userId);

    void checkoutMovie(const int movieId, const int userId);
    void returnMovie(const int movieId);

    void showAllMovies();
    void showMovie(const int movieId);
    void showUser(const int userId);

    void display1(const int movieId);
    void main();
    void DeleteChecked(const int movieId);  //deleting at checked node
    void addChecked(const int movieId, const int userId);//adding at checked node
};

#endif //UNTITLED1_LIBRARYSYSTEM_H
