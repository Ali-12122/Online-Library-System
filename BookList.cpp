#include "BookList.h"
#include <bits/stdc++.h>
#include "User.h"
#include "Book.h"
using namespace std;

template <typename T>
void Swap(T& a, T& b) {
    T tmp;
    tmp = move(a);
    a = move(b);
    b = move(tmp);
}
BookList::BookList(int capacity1){
    this->capacity=capacity1;
    books = new book[this->capacity];
    booksCount=0;
}
BookList::BookList(const BookList& anotherList){
    this->capacity=anotherList.capacity;
    this->booksCount=anotherList.booksCount;
    this->books= anotherList.books;
    for(int i=0;i<anotherList.capacity;++i) {
        books[i]=anotherList.books[i];
    }}
void BookList::addBook(const book& book1) {
    books[booksCount]=book1;
    ++booksCount;
}
book& BookList::searchBook(string const &name)const{
    int pos=0;
    for(int i=0;i<capacity;++i){
        if(books[i].getTitle()==name){pos=i;}}
    return books[pos];
}
book& BookList::searchBook(int id)const{
    int pos=0;
    for(int i=0;i<capacity;++i){
        if(books[i].getId()==id){pos=i;}}
    return books[pos];
}
void BookList::deleteBook(int id){
    int pos=0;
    for(int i=0;i<capacity;++i){
        if(books[i].getId()==id){pos=i;}
    }
    books[pos].setTitle(" ");
    books[pos].setISBN(" ");
    books[pos].setCategory(" ");
    books[pos].setRating(0.0);
    books[pos].setNumOfRatings(0.0);
    books[pos].setSumOfRatings(0.0);
    books[pos].setId(0);
    while (pos!=capacity-1){
        Swap(books[pos],books[pos+1]);
        ++pos;
    }
    --booksCount;
}
book BookList::getTheHighestRatedBook(){
    book highestRatedBook;
    highestRatedBook.setRating(-DBL_MAX);
    for(int i=0;i<capacity;++i){
        if(books[i].getRating()>highestRatedBook.getRating()){highestRatedBook=books[i];}
    }
    return highestRatedBook;
}
book* BookList::getBooksForUser(user const &user1)const {

    for (int i=0;i<capacity;++i){
        if(this->books[i].getAuthor()==user1.getName()){return &books[i];}
        }
   return nullptr;
    }
book BookList::operator[] (int position){return books[position];}

 ostream &operator<<( ostream &output, BookList &bookList ){
     for(int i=0;i<bookList.booksCount;++i){
         output<<"book "<<i+1<<" :"<<bookList.books[i]<<".\n";
     }
     return output;
}
BookList::~BookList(){delete [] this->books;}