#include "User.h"
#include <iostream>
#include <utility>
using namespace std;
template <typename T>
void Swap(T& a, T& b) {
    T tmp;
    tmp = move(a);
    a = move(b);
    b = move(tmp);
}
user::user(){
    name = password = email = " ";
    id = 0;
    age = 0;

}
user::user(string name, int age, string email, string password){
    this->name = move(name);
    this->age = age;
    this->password = move(password);
    this->email = move(email);
    id = UserCount + 1;
    ++UserCount;
}
user::user( user &user){
    name = user.name;
    age = user.age;
    password = user.password;
    email = user.email;
    id = UserCount + 1;
    ++UserCount;
}
// the following is an operator overloading method for the "==" operator,
// since the return type is bool, if the logical statement after the return is true the return value will be true,
// if else it will be false.
bool user:: operator==(const user& user){
    return (( name == user.name) && (age == user.age) && ( id == user.id) && ( email == user.email));
}
void user::operator=(const user&user){//this function used to copy the components of an object into another object.
    name = user.name;
    age = user.age;
    password = user.password;
    email = user.email;
    id = user.id;
}

void user::setName(string name1){ this->name=move(name1);}
string user::getName()const{ return this->name;}
void user::setPassword(string password1) {this->password = move(password1);}
string user::getPassword()const { return this->password;}
void user::setEmail(string email1) {this->email =move(email1); }
string user::getEmail() const { return this->email;}
void user::setAge(int age1) {this->age = age1;}
int user::getAge() const { return this->age;}
void user::setId(int id1) { this->id = id1;}
int user::getId() const { return this->id;}
ostream& operator<<(ostream &output, const user &user) {
    output<<"========== User "<<user.id<<" info==============\n"
          <<"Name: "<<user.name<<" | Age: "<<user.age<<" | ID: "<<user.id<<" | Email: "<<user.email<<"\n"
          <<"================================================================================================\n";
    return output;
}
istream &operator>>( istream &input, user &user ){
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}
void user::swap(user user1,user user2){//this is a swap function for the class to swap the contents of two User objects.
    user temp;
    Swap(temp,user1);
    Swap(user1,user2);
    Swap(user2,user1);
}