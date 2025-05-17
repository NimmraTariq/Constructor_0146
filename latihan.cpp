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
class Admin {
public:
    void viewStats(const Borrower &br, const Book &b) {
        cout << "Stats - Borrower: " << br.name << ", Books borrowed: " << br.totalBorrowed << endl;
        cout << "Book \"" << b.title << "\" is " << (b.isBorrowed ? "borrowed" : "available") << endl;
    }

    void updateAccessLevel(Staff &s, const string &newLevel) {
        s.accessLevel = newLevel;
        cout << "Updated access level for " << s.name << " to " << newLevel << endl;
    }
    // Implement Admin class to view stats and update access levels
};
int main() {
    // Start main function and create sample objects
    Book book1("Clean Code", "Robert C. Martin");
    Borrower borrower1("Alice", 1001);
    Staff staff1("Bob", 2001, "Standard");
    Admin admin1;
    staff1.borrowBook(book1, borrower1);
    borrower1.showStatus();
    book1.displayInfo();
    // Test borrow flow and show borrower/book info
    admin1.viewStats(borrower1, book1);
    admin1.updateAccessLevel(staff1, "Senior");
    // Test Admin viewing stats and updating access level

    staff1.returnBook(book1, borrower1);
    book1.displayInfo();
    // Commit 11: Test return flow and display final book status

    return 0;
}
