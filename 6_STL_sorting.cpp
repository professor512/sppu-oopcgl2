/* Write C++ program using STL for sorting and searching user defined records such as Item 
records (Item code, name, cost, quantity etc) using vector container */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;

    // Overloading the '==' operator to compare items by code
    bool operator==(const Item& i1) {
        return code == i1.code;
    }

    // Overloading the '<' operator for sorting by code
    bool operator<(const Item& i1) {
        return code < i1.code;
    }
};

// Global vector to store Item objects
vector<Item> o1;

// Function declarations
void print(Item &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;  // Sorting based on item cost
}

int main() {
    int ch;
    do {
        cout << "\n*** Menu ***";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(o1.begin(), o1.end(), compare);
                cout << "\n\nSorted on Cost";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nInvalid choice!";
        }
    } while (ch != 6);

    return 0;
}

void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;

    o1.push_back(i1);  // Add the item to the vector
}

void display() {
    for_each(o1.begin(), o1.end(), print);  // Display each item in the vector
}

void print(Item &i1) {
    cout << "\n";
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
}

void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);  // Find the item by code
    if (p == o1.end()) {
        cout << "\nNot found.";
    } else {
        cout << "\nFound.";
        cout << "\nItem Name: " << p->name;
        cout << "\nItem Quantity: " << p->quantity;
        cout << "\nItem Cost: " << p->cost;
        cout << "\nItem Code: " << p->code;
    }
}

void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;

    p = find(o1.begin(), o1.end(), i1);  // Find the item by code
    if (p == o1.end()) {
        cout << "\nNot found.";
    } else {
        o1.erase(p);  // Delete the item
        cout << "\nDeleted.";
    }
}
