#ifndef ONLINE_LIBRARY_SYSTEM_2_USER_H
#define ONLINE_LIBRARY_SYSTEM_2_USER_H

#include <iostream>
#include <cstring>
using namespace std;
class user{
private:
    string name;
    int age;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on
    string password;
    string email;
public:
    static int UserCount;
    user();
    user(string name, int age, string email, string password);
    user( user &user);
    void operator=(const user &user);
    bool operator==(const user& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword()const;
    void setEmail(string email);
    string getEmail()const;
    void setAge(int age);
    int getAge()const;
    void setId(int id);
    int getId()const;
    static void swap(user user1,user user2);
    friend ostream &operator<<(ostream &output, const user &user );
    friend istream &operator>>( istream &input, user &user );
};
#endif //ONLINE_LIBRARY_SYSTEM_2_USER_H
