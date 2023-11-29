#include "library.hpp"
using namespace std;

Library::Library()
{
}

Library::Library(HashTable b, list<User> u)
{
    Items = b;
    users = u;
}

User *Library::getUserAtIndex(int i)
{
    auto usersFront = users.begin();

    advance(usersFront, i);

    return &*usersFront;
}

list<User> Library::getUsers()
{
    return users;
}

HashTable Library::getItems()
{
    return Items;
}

Item Library::getItemByISBN(string isbn)
{
    return Items.lookup(isbn);
}

void Library::addUser(User u)
{
    if (find(users.begin(), users.end(), u) != users.end())
    {
        cout << "User already exists" << endl;
    }
    else
    {
        users.push_back(u);
    }
}

void Library::removeUser(User *u)
{
    users.remove(*u);
}

void Library::displayUsers()
{
    for (auto itr = users.begin(); itr != users.end(); itr++)
    {
        cout << *itr << endl;
    }
}

User Library::findUser(string n)
{
    User emptyUser;
    for (auto itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getName() == n)
        {
            return *itr;
        }
    }

    return emptyUser;
}

template <class T>
void Library::addItem(T b)
{
    Items.insert(b);
}

template <class T>
void Library::removeItem(T b)
{
    if (searchItem(b))
    {
        b.setTitle("");
        Items.update(b);
    }
}

template <class T>
bool Library::searchItem(T b)
{
    if (Items.search(b.getISBN()) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Library::searchItemByTitle(string t)
{
    if (Items.searchByTitle(t))
    {
        cout << t << "was found!" << endl;
        return true;
    }
    else
    {
        cout << t << "was not found..." << endl;
        return false;
    }
}

void Library::displayItems()
{
    cout << Items << endl;
}

void Library::borrowItem(Item i, User *u)
{
    int choice;
    if (searchItem(i))
    {
        switch (i.getAvailable())
        {
        case true:
            i.setAvailable(false);
            i.setDueDate(i.generateDueDate());
            Items.update(i);
            u->borrowItem(i);
            cout << u->getName() << " borrowed: " << i.getTitle() << "! Don't forget to bring it back..." << endl;
            break;
        case false:
            if (i.getReservedBy() == "")
            {
                do
                {
                    cout << "Item is currently being borrowed, would you like to reserve it?" << endl;
                    cout << "(1) YES" << endl;
                    cout << "(2) NO" << endl;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        reserveItem(u->getName(), i);
                        cout << "Reserved!" << endl;
                        break;
                    case 2:
                        cout << "Well, nevermind, have a nice day!" << endl;
                        break;
                    default:
                        cout << "Invalid input, enter 1 or 2" << endl;
                        break;
                    }
                } while (choice != 1 && choice != 2);
                break;
            }
            else
            {
                cout << "Item is currently being borrowed and is reserved. Check back soon!" << endl;
            }
        }
    }
    else
    {
        cout << "Item is not currently in our library, check back soon!" << endl;
    }
}

void Library::returnItem(Item i, User *u)
{
    int choice;
    User reserver;
    if (searchItem(i))
    {
        switch (i.getAvailable())
        {
        case true:
            cout << "Item is not listed as being currently borrowed, did you steal it? Hand it over!" << endl;
            break;
        case false:
            list<string> bItems = u->getBorrowedItems();
            list<string>::iterator itr = find(bItems.begin(), bItems.end(), i.getISBN());
            if (itr != bItems.end())
            {
                i.setAvailable(true);
                Items.update(i);
                u->returnItem(i);
                cout << "Thank you, " << u->getName() << " has returned: " << i.getTitle() << "! We hope you enjoyed it! Come back soon!" << endl;
                if (i.getReservedBy() != "")
                {
                    cout << "Hey, " << i.getReservedBy() << " the Item you reserved: " << i.getTitle() << " is now avaialable!" << endl;
                    do
                    {
                        cout << "Do you want to borrow it?" << endl;
                        cout << "(1) YES" << endl;
                        cout << "(2) NO" << endl;
                        cin >> choice;

                        switch (choice)
                        {
                        case 1:
                            reserver = findUser(i.getReservedBy());
                            unreserve(i);
                            borrowItem(i, &reserver);
                            break;
                        case 2:
                            unreserve(i);
                            cout << "Well, nevermind, have a nice day!" << endl;
                            break;
                        default:
                            cout << "Invalid input, enter 1 or 2" << endl;
                            break;
                        }
                    } while (choice != 1 && choice != 2);
                }
            }
            else
            {
                cout << "Item is currently being borrowed by another user" << endl;
            }
            break;
        }
    }
    else
    {
        do
        {
            cout << "Item is not currently in our library, would you like to donate it to our collection?" << endl;
            cout << "(1) YES" << endl;
            cout << "(2) NO" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                addItem(i);
                break;
            case 2:
                cout << "Well, nevermind, have a nice day!" << endl;
                break;
            default:
                cout << "Invalid input, enter 1 or 2" << endl;
                break;
            }
        } while (choice != 1 && choice != 2);
    }
}

template <class T>
void Library::reserveItem(string n, T i)
{
    i.setReservedBy(n);
    Items.update(i);
}

template <class T>
void Library::unreserve(T i)
{
    i.setReservedBy("");
    Items.update(i);
}

void Library::readInFile()
{
    string readLine;
    string token;
    size_t pos;
    char ItemDelim = '"';
    int count;
    ifstream ItemFile("inventory.txt");

    while (getline(ItemFile, readLine))
    {
        count = 0;
        pos = 0;
        Item newItem;
        while ((pos = readLine.find(ItemDelim)) != string::npos)
        {
            token = readLine.substr(0, pos);
            switch (count)
            {
            case 0:
                token.erase(remove(token.begin(), token.end(), ' '), token.end());
                newItem.setISBN(token);
                break;
            case 1:
                newItem.setTitle(token);
                break;
            case 3:
                //newItem.setAuthor(token);
                break;
            case 4:
                token.erase(remove(token.begin(), token.end(), ' '), token.end());
                if (token == "1")
                {
                    newItem.setAvailable(true);
                }
                else
                {
                    newItem.setAvailable(false);
                }
                break;
            case 5:
                if (token != "")
                {
                    token.erase(remove(token.begin(), token.end(), ' '), token.end());
                    newItem.setDueDate(stoi(token));
                }
                break;
            }
            count++;
            readLine.erase(0, pos + 1);
        }
        if (readLine != "")
        {
            readLine.erase(remove(readLine.begin(), readLine.end(), ' '), readLine.end());
            switch (count)
            {
            case 4:
                if (readLine == "1")
                {
                    newItem.setAvailable(true);
                }
                else
                {
                    newItem.setAvailable(false);
                }
                break;
            case 5:
                newItem.setDueDate(stoi(readLine));
                break;
            case 6:
                newItem.setReservedBy(readLine);
                break;
            }
        }
        addItem(newItem);
    }
    ItemFile.close();
    displayItems();

    ifstream userFile("users.txt");
    string userDelim = " ";

    while (getline(userFile, readLine))
    {
        count = 0;
        pos = 0;
        User newUser;
        while ((pos = readLine.find(userDelim)) != string::npos)
        {
            token = readLine.substr(0, pos);
            switch (count)
            {
            case 0:
                newUser.setID(stoi(token));
                break;
            case 1:
                newUser.setName(token);
                break;
            default:
                //newUser.borrowItem(Items.lookup(token));
                break;
            }
            count++;
            readLine.erase(0, pos + userDelim.length());
        }
        if (readLine != "" && readLine != " ")
        {
            switch (count)
            {
            case 0:
                newUser.setID(stoi(readLine));
                break;
            case 1:
                newUser.setName(readLine);
                break;
            default:
                //newUser.borrowItem(Items.lookup(readLine));
                break;
            }
        }
        addUser(newUser);
    }
    userFile.close();
}

void Library::writeToFile()
{
    ofstream ItemFile("inventory.txt");
    ItemFile << Items;
    ItemFile.close();

    ofstream userFile("users.txt");
    for (auto itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getName() != "")
        {
            userFile << *itr << endl;
        }
    }
    userFile.close();
}