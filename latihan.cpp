#include <iostream>
#include <string>
using namespace std;

//Set up base includes and using namespace std

class Borrower;
class Staff;

// Declare class forward declarations

class Book {
private:
    string title;
    string author;
    bool isBorrowed;
    public:
    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}

    void displayInfo() {
        cout << "Title: " << title << ", Author: " << author 
             << ", Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    friend class Staff; // Implement Book class with private status and friend Staff
};
class Borrower {
private:
    string name;
    int id;
    int totalBorrowed;

public:
    Borrower(string n, int i) : name(n), id(i), totalBorrowed(0) {}

    void showStatus() {
        cout << "Borrower Name: " << name << ", ID: " << id 
             << ", Total Borrowed: " << totalBorrowed << endl;
    }

    friend class Staff;  // Create Borrower class and make Staff a friend
    friend class Admin;  // Allow Admin to view borrower stats via friendship
};
class Staff {
private:
    string name;
    int staffId;
    string accessLevel;

public:
    Staff(string n, int i, string access) : name(n), staffId(i), accessLevel(access) {}

    void borrowBook(Book &b, Borrower &br) {
        if (!b.isBorrowed) {
            b.isBorrowed = true;
            br.totalBorrowed++;
            cout << br.name << " borrowed \"" << b.title << "\"\n";
        } else {
            cout << "Book is already borrowed.\n";
        }
    }
     void returnBook(Book &b, Borrower &br) {
        if (b.isBorrowed) {
            b.isBorrowed = false;
            br.totalBorrowed--;
            cout << br.name << " returned \"" << b.title << "\"\n";
        } else {
            cout << "Book was not borrowed.\n";
        }
    }

    friend class Admin; //Implement Staff class and make Admin a friend
};