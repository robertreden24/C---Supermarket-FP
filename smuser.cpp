#include <iostream>
#include <string>
#include "smuser.h"
using namespace std;

//constructor for user object
User::User(string un, string pass){
    username = un;
    password = pass;
}

//setter function for User's username
void User::setUsername(string un){
    username = un;
}

//setter function for User's password
void User::setPassword(string pass){
    password = pass;
}

//getter function for User's username
string User::getUsername(){
    return username;
}

//getter function for User's password
string User::getPassword(){
    return password;
}

