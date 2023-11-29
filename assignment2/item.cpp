#include "item.hpp"
#include <iostream>
using namespace std;

Item::Item()
{
    type =-1;
    title = "";
    ISBN = "";
    available = false;
    dueDate = -1;
    reservedBy = "";
}

Item::Item(int tp, string ttl, string isbn, bool avlbl, int ddt, string r)
{
    type = tp;
    title = ttl;
    ISBN = isbn;
    available = avlbl;
    dueDate = ddt;
    reservedBy = r;
}

string Item::getTitle()
{
    return title;
}

string Item::getISBN()
{
    return ISBN;
}

bool Item::getAvailable()
{
    return available;
}

int Item::getDueDate()
{
    return dueDate;
}

string Item::getReservedBy()
{
    return reservedBy;
}

void Item::setTitle(string ttl)
{
    title = ttl;
}

void Item::setISBN(string isbn)
{
    ISBN = isbn;
}

void Item::setAvailable(bool avlbl)
{
    available = avlbl;
}

void Item::setDueDate(int ddt)
{
    dueDate = ddt;
}

void Item::setReservedBy(string r)
{
    reservedBy = r;
}

int Item::generateDueDate()
{

    auto now = chrono::system_clock::now();
    auto twoWeeks = now + chrono::hours(24 * 14);
    time_t dueDate = chrono::system_clock::to_time_t(twoWeeks);
    return dueDate;
}

time_t Item::intToTime(int i)
{
    time_t t = i;
    return i;
}

double Item::generateLateFee(int d)
{
    double lateFee;
    lateFee = (d / 86400) * 1.5;
    return lateFee;
}

/*ostream &operator<<(std::ostream &output, const Book &b)
{
    char quotations = '"';
    string avlbl;

    if (b.available)
    {
        avlbl = " 1";
    }
    else
    {
        avlbl = " 0";
    }

    if (b.available || b.dueDate == -1)
    {
        output << b.ISBN << ' ' << quotations << b.title << quotations << ' ' << quotations << b.author << quotations << avlbl;
    }
    else
    {
        if (b.reservedBy == "")
        {
            output << b.ISBN << ' ' << quotations << b.title << quotations << ' ' << quotations << b.author << quotations << avlbl << ' ' << quotations << b.dueDate;
        }
        else
        {
            output << b.ISBN << ' ' << quotations << b.title << quotations << ' ' << quotations << b.author << quotations << avlbl << ' ' << quotations << b.dueDate << quotations << ' ' << b.reservedBy;
        }
    }

    return output;
}*/

