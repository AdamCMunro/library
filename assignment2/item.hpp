#ifndef ITEMH
#define ITEMH
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <string>
#include <algorithm>
using namespace std;

class Item
{
    int type;
    string title;
    string ISBN;
    bool available;
    int dueDate;
    string reservedBy;

public:
    Item();
    Item(int tp, string ttl, string isbn, bool avlbl, int ddt, string r);
    int getType();
    string getTitle();
    string getISBN();
    bool getAvailable();
    int getDueDate();
    string getReservedBy();
    int setType();
    void setTitle(string ttl);
    void setISBN(string isbn);
    void setAvailable(bool avlbl);
    void setDueDate(int ddt);
    void setReservedBy(string r);
    int generateDueDate();
    time_t intToTime(int i);
    double generateLateFee(int d);

    template <class T>
    friend std::ostream &operator<<(std::ostream &output, const T &i);
};

#endif

#ifndef BOOKH
#define BOOKH

class Book : public Item
{
    string author;

public:
    Book():Item(), author("") {};
    Book(int tp, string ttl, string athr, string isbn, bool avlbl, int ddt, string r): Item(tp, ttl, isbn, avlbl, ddt, r), author(athr) {};
    string getAuthor()
    {
        return author;
    }
    void setAuthor(string athr)
    {
        author = athr;
    }

    friend std::ostream &operator<<(std::ostream &output, const Book &b);
};

#endif

#ifndef CDH
#define CDH

class CD : public Item
{
    string artist;
    int trackNum;
    string *trackList;

public:
    CD():Item(), artist(""), trackNum(-1) {};
    CD(int tp, string ttl, string artst, int trcknm, string *trcklst, string isbn, bool avlbl, int ddt, string r): Item(tp, ttl, isbn, avlbl, ddt, r), artist(artst), trackNum(trcknm), trackList(trcklst) {};
    string getArtist();
    int getTrackNum();
    string *getTrackList();
    void setArtist(string artst);
    void setTrackNum(int trcknm);
    void setTrackList(string *trcklst);

    friend std::ostream &operator<<(std::ostream &output, const CD &b);
};

#endif

#ifndef DVDH
#define DVDH

class DVD : public Item
{
    string director;
    string *cast;
    int runtime;

public:
    DVD():Item(), director(""), runtime(-1) {};
    DVD(int tp, string ttl, string drctr, string *cst, int rntme, string isbn, bool avlbl, int ddt, string r): Item(tp, ttl, isbn, avlbl, ddt, r), director(drctr), cast(cst), runtime(rntme) {};
    string getDirector();
    string *getCast();
    int getRuntime();
    void setDirector(string *drctr);
    void setCast(string *cst);
    void setRuntime(int rntm);

    friend std::ostream &operator<<(std::ostream &output, const DVD &b);
};

#endif

#ifndef COMICH
#define COMICH

class Comic : public Item
{
    string writer;
    string *artists;
    int issueNum;

public:
    Comic():Item(), writer(""), issueNum(-1) {};
    Comic(int tp, string ttl, string wrtr, string *artsts, int issnm, string isbn, bool avlbl, int ddt, string r): Item(tp, ttl, isbn, avlbl, ddt, r), writer(wrtr), artists(artsts), issueNum(issnm) {};
    string getWriter();
    string *getArtists();
    int getIssueNum();
    void setWriter(string wrtr);
    void setArtists(string *artsts);
    void setIssueNum(int issnm);
};

#endif