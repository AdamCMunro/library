#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "library.hpp"
#include "item.hpp"
using namespace std;

void basicTester();
void dueDateReadWrite();
void reservationTest();
void itemTest();

int main()
{

    // basicTester();

    // dueDateReadWrite();

    //reservationTest();

    itemTest();

    return 0;
}

void basicTester()
{
    Library lib;

    lib.readInFile();
    lib.displayItems();
    lib.displayUsers();

    //Item newItem = Item("The Caves of Steel", "Isaac Asimov", "978-7-8912-3456-8", true, -1, "");
    //lib.addItem(newItem);

    lib.displayItems();

    lib.borrowItem(lib.getItemByISBN("978-7-8912-3456-8"), lib.getUserAtIndex(1));

    lib.displayItems();
    lib.displayUsers();

    lib.borrowItem(lib.getItemByISBN("978-7-8912-3456-8"), lib.getUserAtIndex(4));

    lib.returnItem(lib.getItemByISBN("978-7-8912-3456-8"), lib.getUserAtIndex(1));

    lib.displayItems();
    lib.displayUsers();

    // lib.removeItem(lib.getItemByISBN(newItem.getISBN()));
    // lib.removeUser(lib.getUserAtIndex(1));

    User newUser = User(109, "Adam");
    lib.addUser(newUser);

    lib.displayItems();
    lib.displayUsers();

    lib.writeToFile();
}

void dueDateReadWrite()
{
    Library lib;
    lib.readInFile();
    cout << "Due Date: " << lib.getItemByISBN("978-7-8912-3456-8").intToTime(lib.getItemByISBN("978-7-8912-3456-8").getDueDate()) << endl;
    lib.returnItem(lib.getItemByISBN("978-7-8912-3456-8"), lib.getUserAtIndex(1));
    lib.displayItems();
    lib.borrowItem(lib.getItemByISBN("978-7-8912-3456-8"), lib.getUserAtIndex(1));
    lib.writeToFile();
}

void reservationTest()
{
    Library lib;
    lib.readInFile();
    // lib.borrowItem(lib.getItemByISBN("978-3-4567-8912-3"), lib.getUserAtIndex(0));
    // lib.borrowItem(lib.getItemByISBN("978-3-4567-8912-3"), lib.getUserAtIndex(5));
    lib.returnItem(lib.getItemByISBN("978-3-4567-8912-3"), lib.getUserAtIndex(1));
    lib.writeToFile();
}

void itemTest()
{
    Book b = Book(1, "Hey", "You", "978-3-4567-8912-9", true, -1, "");
    cout << b.getTitle() << endl;
    cout << b.getAuthor() << endl;
    cout << b << endl;
}