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