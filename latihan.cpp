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
    friend class Admin;  // Commit 5: Allow Admin to view borrower stats via friendship
};