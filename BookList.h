#ifndef ONLINE_LIBRARY_SYSTEM_2_BOOKLIST_H
#define ONLINE_LIBRARY_SYSTEM_2_BOOKLIST_H

#include <bits/stdc++.h>
#include "User.h"
#include "Book.h"
using namespace std;
class BookList{
private:
book *books;
int capacity;
int booksCount;
public:
BookList(const BookList& anotherList);
explicit BookList(int capacity);
void addBook(const book& book1);
book& searchBook(string const &name)const;
book& searchBook(int id)const;
void deleteBook(int id); //delete a book
book getTheHighestRatedBook();
book* getBooksForUser(user const &user)const ; // get all books of this author
book  operator [] (int position);
friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books
~BookList();

};
#endif //ONLINE_LIBRARY_SYSTEM_2_BOOKLIST_H
