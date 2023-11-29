#ifndef LIBRARY
#define LIBRARY
#include <stdio.h>
#include <iostream>
#include "hashTable.hpp"
#include "user.hpp"
#include "item.hpp"
#include <algorithm>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Library
{

    HashTable Items;
    list<User> users;

public:
    Library();
    Library(HashTable i, list<User> u);
    list<User> getUsers();
    User *getUserAtIndex(int i);
    HashTable getItems();
    Item getItemByISBN(string isbn);
    void addUser(User u);
    void removeUser(User *u);
    void displayUsers();
    User findUser(string n);
    template <class T>
    void addItem(T i);
    template <class T>
    void removeItem(T i);
    template <class T>
    bool searchItem(T i);
    bool searchItemByTitle(string t);
    void displayItems();
    void borrowItem(Item i, User *u);
    void returnItem(Item i, User *u);
    template <class T>
    void reserveItem(string n, T i);
    template <class T>
    void unreserve(T i);
    void readInFile();
    void writeToFile();
};

#endif