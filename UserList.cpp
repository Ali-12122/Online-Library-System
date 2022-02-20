#include "UserList.h"
#include <iostream>
#include "User.h"

template <typename T>
void Swap(T& a, T& b) {
    T tmp;
    tmp = move(a);
    a = move(b);
    b = move(tmp);
}
UserList::UserList(int capacity){
    this->capacity=capacity;
    users = new user[capacity];
    usersCount=0;}
void  UserList::addUser(user const &user){
    users[usersCount]=user;
    ++usersCount;}
user& UserList::searchUser(string const &name){
    int pos=0;
    for(int i=0;i<capacity;++i) {
        if(users[i].getName()==name) {pos=i;}}
    return users[pos];
}
user& UserList::searchUser(int id){
    int pos=0;
    for(int i=0;i<capacity;++i){
        if(users[i].getId()==id){pos=i;}}
    return users[pos];
}
void UserList::deleteUser(int id){
    int pos = 0;
    for(int i=0;i<capacity;++i){
        if(users[i].getId()==id){pos=i;}
    }
    users[pos].setName(" ");
    users[pos].setEmail(" ");
    users[pos].setPassword(" ");
    users[pos].setId(0);
    users[pos].setAge(0);
    while(pos!=capacity-1){
        Swap(users[pos],users[pos+1]);
        ++pos;
    }
    --usersCount;
    }
ostream &operator<<( ostream &output, UserList &userList ){
    for(int i=0;i<userList.usersCount;++i){
        output<<"user "<<i+1<<" :"<<userList.users[i]<<'\n';}
    return output;
    }

UserList::~UserList(){delete [] this->users;}


