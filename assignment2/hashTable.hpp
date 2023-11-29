#ifndef HASHTABLE
#define HASHTABLE
#include "item.hpp"
#include <iostream>
using namespace std;

class HashTable
{
private:
    int tablesize;
    Item *table;

public:
    HashTable();
    HashTable(int size);
    ~HashTable();

    int hashFunction(string k);
    bool insert(Item node);
    int search(string k);
    bool generalSearch(string s);
    bool searchByTitle(string t);
    bool fuzzySearch(string a, string b);
    bool update(Item i);
    Item lookup(string k);

    template <class T>
    T minimum (T a, T b, T c);

    friend std::ostream &operator<<(std::ostream &output, const HashTable &ht);
    friend std::ostream &operator<<(std::ostream &output, const HashTable &ht);
};
#endif