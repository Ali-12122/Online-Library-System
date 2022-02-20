#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
int user::UserCount=0;
int book::BookCount=0;
using namespace std;
int main() {

//Userlist Functions.
UserList list1(4);

string name1="Tom",name2="Jake", name3="Mike", name4="Paul";
string password1 = "1234", password2 = "5678", password3 = "91011", password4 = "12131415";
string email1 = "tom@gmail.com", email2 = "jake@gmail.com", email3 = "mike@gmail.com", email4 = "paul@gmail.com";
int age1 = 21, age2 = 22, age3 = 23, age4 = 24 ;

user u1(name1, age1, email1, password1);
user u2(name2, age2, email2, password2);
user u3(name3, age3, email3, password3);
user u4(name4, age4, email4, password4);

list1.addUser(u1);
list1.addUser(u2);
list1.addUser(u3);
list1.addUser(u4);

cout<<list1.searchUser("tom")<<'\n';
cout<<list1.searchUser(3)<<'\n';
list1.deleteUser(4);
cout<<list1<<'\n';


//Booklist Functions

BookList list2(4);
string title1 = "book1", title2 = "book2", title3 = "book3", title4 = "book4";
string isbn1 = "1234", isbn2 = "5678", isbn3 = "91011", isbn4 = "1213";
string category1 = "cat1", category2 = "cat2", category3 = "cat3", category4 ="cat4";

string AuthorOfBook="joe", passwordOfAuthor="1200",emailOfAuthor="joe@gmail.com";
int ageOfAuthor= 25;
user userA(AuthorOfBook,ageOfAuthor,emailOfAuthor,passwordOfAuthor);


book b1(title1,isbn1,category1);
book b2(title2,isbn2,category2);
book b3(title3,isbn3,category3);
book b4(title4,isbn4,category4);

b1.rateBook(5.0);
b2.setAuthor(userA);

list2.addBook(b1);
list2.addBook(b2);
list2.addBook(b3);
list2.addBook(b4);



cout<<list2.searchBook(2)<<'\n';
cout<<list2.searchBook("book3")<<'\n';
list2.deleteBook(4);
cout<<list2.getTheHighestRatedBook()<<endl;
cout<<*(list2.getBooksForUser(userA))<<endl;
cout<<list2;
  return 0;
}
