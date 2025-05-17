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
