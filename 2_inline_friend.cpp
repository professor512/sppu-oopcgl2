/*Develop an object oriented program in C++ to create a database of student information system containing the
following information: Name, Roll number, Class, division, Date of Birth, Blood group, Contact address, telephone
number, driving license no. etc Construct the database with suitable member functions for initializing and destroying
the data viz constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this
pointer, inline code and dynamic memory allocation operators-new and delete.
*/


#include <iostream>
#include <string.h>
using namespace std;

// Class for storing additional info about the person
class person_additional_info {
    char address[20], license[20], insurance[20];
    long int contact;

public:
    // Default constructor
    person_additional_info() {
        strcpy(address, "XYZ");
        strcpy(license, "XY-0000000000");
        strcpy(insurance, "XY00000000X");
        contact = 000000000;
    }

    // Destructor
    ~person_additional_info() {
        cout << "I am in Destructor for person_additional_info\n";
    }

    // Friend class declaration
    friend class person;
};

// Definition of friend class 'person'
class person {
    char name[20], dob[10], blood[10];
    float ht, wt;
    static int count;                // Static variable to keep track of records
    person_additional_info* pai;     // Pointer to person_additional_info

public:
    // Default constructor
    person() {
        strcpy(name, "XYZ");
        strcpy(dob, "dd/mm/yy");
        strcpy(blood, "A+");
        ht = 0;
        wt = 0;
        pai = new person_additional_info;
    }

    // Copy constructor
    person(person* p1) {
        strcpy(name, p1->name);
        strcpy(dob, p1->dob);
        strcpy(blood, p1->blood);
        ht = p1->ht;
        wt = p1->wt;
        pai = new person_additional_info;
        strcpy(pai->address, p1->pai->address);
        strcpy(pai->license, p1->pai->license);
        strcpy(pai->insurance, p1->pai->insurance);
        pai->contact = p1->pai->contact;
    }

    // Static member function to show record count
    static void showcount() {
        cout << "\nNo of records count = " << count << "\n";
    }

    // Destructor
    ~person() {
        cout << "\nI am in Destructor for person\n";
        delete pai;  // Free dynamically allocated memory
    }

    // Function to get data using this pointer
    void getdata(char name[20]) {
        strcpy(this->name, name);
        cout << "\nEnter date of birth: ";
        cin >> dob;
        cout << "\nEnter blood group: ";
        cin >> blood;
        cout << "\nEnter height: ";
        cin >> ht;
        cout << "\nEnter weight: ";
        cin >> wt;
        cout << "\nEnter address: ";
        cin >> pai->address;
        cout << "\nEnter license number: ";
        cin >> pai->license;
        cout << "\nEnter insurance policy number: ";
        cin >> pai->insurance;
        cout << "\nEnter contact number: ";
        cin >> pai->contact;
        count++;
    }

    // Inline function to display data
    inline void display() {
        cout << "\t" << name
             << "\t" << dob
             << "\t" << blood
             << "\t" << ht
             << "\t" << wt
             << "\t" << pai->address
             << "\t" << pai->license
             << "\t" << pai->insurance
             << "\t" << pai->contact << endl;
    }
};

// Static variable initialization
int person::count = 0;

int main() {
    person *p1, *p2;
    int ch;

    // Dynamic memory allocation and constructor calls
    p1 = new person;
    p2 = new person(p1); // Call copy constructor

    // Display the default constructor and copy constructor values
    cout << "\tName\tDob\tBlood\tHt\tWt\tAddress\tLicense\tInsurance\tContact\n";
    cout << "Default Constructor Value:\n";
    p1->display();
    cout << "\nCopy Constructor Value:\n";
    p2->display();

    int n;
    cout << "\nEnter how many records you want? ";
    cin >> n;
    person p3[n];  // Array of person objects
    char name[20];
    int x = 0;

    do {
        cout << "\nWelcome to Personal Database System";
        cout << "\n1. Enter the record";
        cout << "\n2. Display the record";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "\nEnter the Name: ";
                cin >> name;
                p3[x].getdata(name);     // Get data for person object
                person::showcount();      // Show record count
                x++;
                break;
            }
            case 2: {
                cout << "\tName\tDob\tBlood\tHt\tWt\tAddress\tLicense\tInsurance\tContact\n";
                for (int i = 0; i < n; i++) {
                    cout << "\n";
                    p3[i].display();      // Display details of each person
                }
                break;
            }
        }
    } while (ch != 3);

    // Free dynamically allocated memory
    delete p1;
    delete p2;

    return 0;
}
