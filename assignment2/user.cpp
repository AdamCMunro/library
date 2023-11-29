#include "user.hpp"
using namespace std;

User::User()
{
    ID = 0;
    name = "";
}

User::User(int id, string nm)
{
    ID = id;
    name = nm;
}

User::User(int id, string nm, list<string> brrwdBks)
{
    ID = id;
    name = nm;
    borrowedItems = brrwdBks;
}

int User::getID()
{
    return ID;
}

string User::getName()
{
    return name;
}

list<string> User::getBorrowedItems()
{
    return borrowedItems;
}

void User::setID(int id)
{
    ID = id;
}

void User::setName(string nm)
{
    name = nm;
}

void User::returnItem(Item i)
{
    int timeDiff = difftime(chrono::system_clock::to_time_t(chrono::system_clock::now()), i.intToTime(i.getDueDate()));
    char pound = 156;
    if (timeDiff > 86400)
    {
        cout << "You're late!" << endl;
        cout << "Late fee is: " << pound << setprecision(2) << fixed << i.generateLateFee(timeDiff) << "!" << endl;
    }
    borrowedItems.remove(i.getISBN());
}

void User::borrowItem(Item i)
{
    borrowedItems.push_back(i.getISBN());
}

void User::reserveItem(Item i)
{
    i.setReservedBy(name);
}

ostream &operator<<(ostream &output, const User &u)
{
    output << u.ID << " " << u.name << " ";
    for (auto itr = u.borrowedItems.begin(); itr != u.borrowedItems.end(); itr++)
    {
        if (*itr != "")
        {
            output << *itr << " ";
        }
    }
    return output;
}