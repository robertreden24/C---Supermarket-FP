#include <iostream>
#include <string>
#include "smuser.h"
using namespace std;

User::User(string un, string pass){
    username = un;
    password = pass;
}

void User::setUsername(string un){
    username = un;
}

void User::setPassword(string pass){
    password = pass;
}

string User::getUsername(){
    return username;
}

string User::getPassword(){
    return password;
}

