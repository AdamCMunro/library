/*#ifndef BOOK
#define BOOK
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <string>
#include <algorithm>
using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;
    bool available;
    int dueDate;
    string reservedBy;

public:
    Book();
    Book(string ttl, string athr, string isbn, bool avlbl, int ddt, string r);
    string getTitle();
    string getAuthor();
    string getISBN();
    bool getAvailable();
    int getDueDate();
    string getReservedBy();
    void setTitle(string ttl);
    void setAuthor(string athr);
    void setISBN(string isbn);
    void setAvailable(bool avlbl);
    void setDueDate(int ddt);
    void setReservedBy(string r);
    int generateDueDate();
    time_t intToTime(int i);
    double generateLateFee(int d);

    friend std::ostream &operator<<(std::ostream &output, const Book &b);
};

#endif*/
