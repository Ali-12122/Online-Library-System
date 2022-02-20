#include "Book.h"
#include <iostream>
#include <utility>
#include "User.h"
using namespace std;
template <typename T>
void Swap(T& a, T& b) {
    T tmp;
    tmp = move(a);
    a = move(b);
    b = move(tmp);
}
book::book(){
    title=isbn=category=" ";
    id = 0;
    averageRating = 0;
    sumOfRatings = numOfRatings = 0;
}
book::book(string title, string isbn, string category) {
    this->title = move(title);
    this->isbn = move(isbn);
    this->category = move(category);
    this->sumOfRatings = 0;
    this->numOfRatings = 0;
    author;
    this->averageRating = 0;
    this->id = BookCount+1;
    ++BookCount;
}
book::book(const book &book){
    this->title = book.title;
    this->isbn = book.isbn;
    this->category = book.category;
    this->sumOfRatings = book.sumOfRatings;
    this->numOfRatings = book.numOfRatings;
    this->author=book.author;
    this-> averageRating = book.averageRating;
    id = BookCount+1;
   // ++BookCount;
}
void book::setTitle(string const &title1){ this->title=title1;}
string book::getTitle()const { return title;}
void book::setISBN(string const &isbn1){this->isbn=isbn1;}
string book::getISBN()const{return isbn;}
void book::setId(int id1){this->id=id1;}
int book::getId()const{ return id;}
void book::setCategory(string const &category1){this->category=category1;}
string book::getCategory()const { return category;}
void book::setAuthor(user const &user1){author=user1;}
string book::getAuthor()const{ return author.getName();};
double book::getRating()const{ return averageRating;}
void book::setRating(double rating){averageRating=rating;}
void book::setSumOfRatings(double sum){sumOfRatings=sum;}
void book::setNumOfRatings(double num){numOfRatings=num;}
void book::rateBook(double rating){
    if(rating>5.0){rating=5.0;}
    ++numOfRatings;
    sumOfRatings += rating;
    averageRating = sumOfRatings/numOfRatings;
};
bool book::operator==(const book& book){
    return ((title==book.title) && (isbn==book.isbn) && (category==book.category) && (id==book.id) && (author==book.author));
};
ostream &operator<<(ostream &output, const book &book ){
    output<<"================== Book "<<book.id<<" info ================================\n"
          <<"Title: "<<book.title<<" | ISBN: "<<book.isbn<<" | Category: "<<book.category<<" | Average Rating: "<<book.averageRating
          <<"\n==============================================================================================\n";
    return output;
};
istream &operator>>( istream &input, book &book ){
    input>>book.title>>book.isbn>>book.category;
    return input;
}

void book::operator=(const book &book){ //this function used to copy the components of an object into another object.
    this->title = book.title;
    this->isbn = book.isbn;
    this-> category = book.category;
    this->sumOfRatings = book.sumOfRatings;
    this->numOfRatings = book.numOfRatings;
    this->author=book.author;
    this->averageRating = book.averageRating;
    this->id =book.id;
}
/*void book::Swap(book book1, book book2){//this is a swap function for the class to swap the contents of two Book objects.
    book temp;
    Swap(temp,book1);
    Swap(book1,book2);
    Swap(book2,temp);
}*/
book::~book() = default;
