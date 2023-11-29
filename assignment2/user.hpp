#ifndef USER
#define USER
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <list>
#include "Item.hpp"
using namespace std;

class User
{

    int ID;
    string name;
    list<string> borrowedItems;

public:
    User();
    User(int id, string nm);
    User(int id, string nm, list<string> brrwditms);
    int getID();
    string getName();
    list<string> getBorrowedItems();
    void setID(int id);
    void setName(string nm);
    void returnItem(Item i);
    void borrowItem(Item i);
    void reserveItem(Item i);
    friend bool operator==(const User &lhs, const User &rhs)
    {
        return lhs.ID == rhs.ID && lhs.name == rhs.name && lhs.borrowedItems == rhs.borrowedItems;
    }

    friend std::ostream &operator<<(std::ostream &output, const User &u);
};

#endif