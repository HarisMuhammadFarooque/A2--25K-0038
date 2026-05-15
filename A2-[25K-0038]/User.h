#pragma once
#include <iostream>
#include <string>
using namespace std;

class User{
protected:
    const string userID;
    string name;
    string email;
    string phoneNumber;
    string address;

public:
    User() : userID(""), name(""), email(""), phoneNumber(""), address("") {} 
    User(string id, string n, string e, string p, string a) : userID(id), name(n), email(e), phoneNumber(p), address(a) {}  
    
    virtual void displayDetails() = 0; // Pure virtual function to make User an abstract class

};
