/*Imagine a publishing company that markets both book and audiocassette versions of its works. Create a class
publication that stores the title (a string) and price (type float) of a publication. From this class derive two classes:
book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Each of these
three classes should have a getdata() function to get its data from the user at the keyboard, and a putdata() function to
display its data. Write a main() program to test the book and tape classes by creating instances of them, asking the
user to fill in data with getdata(), and then displaying the data with putdata().
*/



#include <iostream>
using namespace std;

// Base class 'publication'
class publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    publication() {
        title = "";
        price = 0.0;
    }

    // Parameterized constructor
    publication(string t, float p) {
        title = t;
        price = p;
    }
};

// Derived class 'book' from 'publication'
class book : public publication {
private:
    int pages;

public:
    // Default constructor
    book() : publication() {
        pages = 0;
    }

    // Parameterized constructor with validation
    book(string t, int p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            pages = p;
        } else {
            throw(0);  // Throw an exception if the input is invalid
        }
    }

    // Function to display book details
    void display() {
        cout << title << " | " << price << " | " << pages << " pages" << endl;
    }
};

// Derived class 'tape' from 'publication'
class tape : public publication {
private:
    float mins;

public:
    // Default constructor
    tape() : publication() {
        mins = 0.0;
    }

    // Parameterized constructor with validation
    tape(string t, float p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            mins = p;
        } else {
            throw(0);  // Throw an exception if the input is invalid
        }
    }

    // Function to display tape details
    void display() {
        cout << title << " | " << price << " | " << mins << " mins" << endl;
    }
};

int main() {
    int pages;
    float price;
    string title;

    // Input book details
    cout << "Enter Book Details: Title | Pages | Price" << endl;
    cin >> title >> pages >> price;

    float mins, pr;
    string t;

    // Input tape details
    cout << "Enter Tape Details: Title | Mins | Price" << endl;
    cin >> t >> mins >> pr;

    book b;
    tape t1;

    // Try-catch block for handling exceptions
    try {
        b = book(title, pages, price);
        t1 = tape(t, mins, pr);
    } catch (...) {
        cout << "Error: Invalid input!" << endl;
        b = book("", 0, 0);
        t1 = tape("", 0, 0);
    }

    // Display the details of the book and tape
    b.display();
    t1.display();

    return 0;
}
