#include "HashTable.hpp"
#include <iostream>
using namespace std;

HashTable::HashTable()
{
    tablesize = 10;
    table = new Item[10];
}

HashTable::HashTable(int size)
{
    tablesize = size;
    table = new Item[size];
}

HashTable::~HashTable()
{
    delete[] table;
}

int HashTable::hashFunction(string k)
{
    int hash = int(k.back()) - 48;

    while (hash >= tablesize)
    {
        hash = hash - tablesize;
    }

    return hash;
}

bool HashTable::insert(Item node)
{
    int index;
    index = hashFunction(node.getISBN());
    for (int count = 0; count < tablesize; count++)
    {
        if (table[index].getTitle() == "")
        {
            table[index] = node;
            return true;
        }
        else if (table[index].getISBN() == node.getISBN())
        {
            cout << "Item already exists with that ISBN" << endl;
            return false;
        }
        else if (index < tablesize)
        {
            index++;
        }
        else
        {
            index = 0;
        }
    }
    return false;
}

int HashTable::search(string k)
{
    int index;
    index = hashFunction(k);
    for (int count = 0; count < tablesize; count++)
    {
        if (table[index].getISBN() == k)
        {
            return index;
        }
        else if (index < tablesize)
        {
            index++;
        }
        else
        {
            index = 0;
        }
    }
    return -1;
}

bool HashTable::generalSearch(string s)
{
    bool found;
    string avlbl;
    found = false;
    for (int i = 0; i < tablesize; i++)
    {
        switch (table[i].getAvailable())
        {
            case true:
                avlbl = "true";
                break;
            case false:
                avlbl = "false";
                break;
        }
        //if (fuzzySearch(s, table[i].getTitle()) || fuzzySearch(s, table[i].getAuthor()) || fuzzySearch(s, avlbl))
        //{
            //found = true;
            //cout << table[i] << endl;
       // }
    }
   return found;
}

bool HashTable::searchByTitle(string t)
{
    for (int i = 0; i < tablesize; i++)
    {
        if (table[i].getTitle() == t)
        {
            return true;
        }
    }
    return false;
}

bool HashTable::fuzzySearch(string a, string b)
{
    int substitutionCost;
    int d[a.length()+1][b.length()+1];
    for (int i = 1; i < a.length()+1; i++)
    {
        for (int j = 1; j < b.length()+1; j++)
        {
            d[i][j] = 0;
        }
    }

    for (int i = 1; i < a.length()+1; i++)
    {
        d[i][0] = i;
    }

    for (int j = 1; j < b.length()+1; j++)
    {
        d[0][j] = j;
    }

    for (int j = 1; j < b.length()+1; j++)
    {
        for (int i = 1; i < a.length()+1; i++)
        {
            if (a[i-1] == b[j-1])
            {
                substitutionCost += 0;
            }
            else
            {
                substitutionCost += 1;
            }
            d[i][j] = minimum<int>(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + substitutionCost);
        }
    }
    if (d[a.length()][b.length()] <= 3)
    {
        return true;
    }
    return false;
}

template <typename T>
T HashTable::minimum(T a, T b, T c)
{
    int minimum;
    minimum = a;
    if (b < minimum && c > b) {
        minimum = b;
    }
    else if (c < minimum) {
        minimum = c;
    }
    return minimum;
}

bool HashTable::update(Item b)
{
    int index;
    index = search(b.getISBN());
    if (index == -1)
    {
        return false;
    }
    else
    {
        table[index].setTitle(b.getTitle());
        table[index].setISBN(b.getISBN());
        table[index].setAvailable(b.getAvailable());
        table[index].setDueDate(b.getDueDate());
        table[index].setReservedBy(b.getReservedBy());
        return true;
    }
}

Item HashTable::lookup(string k)
{
    int index;
    index = search(k);
    if (index != -1)
    {
        return table[index];
    }
    Item Item;
    return Item;
}

ostream &operator<<(ostream &output, const HashTable &ht)
{
    for (int i = 0; i < ht.tablesize; i++)
    {
        if (ht.table[i].getTitle() != "")
        {
            //output << ht.table[i] << endl;
        }
    }
    return output;
}