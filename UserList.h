#ifndef ONLINE_LIBRARY_SYSTEM_2_USERLIST_H
#define ONLINE_LIBRARY_SYSTEM_2_USERLIST_H

#include <iostream>
#include "User.h"
#include "Book.h"
using namespace std;
class UserList{
private:
user* users;
int capacity;
int usersCount;
public:
explicit UserList(int capacity);
void addUser(user const &user1); // at the end of the array.
user& searchUser(string const &name);
user& searchUser(int id);
void deleteUser(int id);
friend ostream &operator<<( ostream &output, UserList &userList );
~UserList();
};
#endif //ONLINE_LIBRARY_SYSTEM_2_USERLIST_H
