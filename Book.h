#ifndef ONLINE_LIBRARY_SYSTEM_2_BOOK_H
#define ONLINE_LIBRARY_SYSTEM_2_BOOK_H

#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;
class book{
private:
    string title, isbn, category;
    int id;
    double averageRating, sumOfRatings, numOfRatings;//those to variables are needed to calculate averageRating
    user author;
public:
    static int BookCount;
    book();
    ~book();
    book(string title, string isbn, string category);
    book(const book& book);
    void setTitle(string const &title);
    string getTitle()const;
    void setISBN(string const &isbn);
    string getISBN()const;
    void setId(int id);
    int getId()const ;
    void setCategory(string const &category);
    string getCategory()const ;
    void setAuthor(user const &user);
    string getAuthor()const ;
    void rateBook(double rating);
    void setRating(double rating);
    void setSumOfRatings(double sum);
    void setNumOfRatings(double num);
    bool operator==(const book& book);
    friend ostream &operator<<(ostream &output, const book &book );
    friend istream &operator>>( istream &input, book &book );
    void  operator=(const book& book);
    double getRating()const;
    static void Swap(book book1, book book2);

};
#endif //ONLINE_LIBRARY_SYSTEM_2_BOOK_H
