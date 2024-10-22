/* Write a C++ program that creates an output file, writes information to it,
closes the file, open it again as an input file and read the information from the
file. */

#include <iostream>
#include <fstream>
using namespace std;

class Employee {
    char name[20];  // Variable declaration for employee name
    int emp_id;     // Variable declaration for employee ID
    float salary;   // Variable declaration for employee salary

public:
    // Function to accept employee details
    void accept() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() {
        cout << "\n" << name << "\t" << emp_id << "\t" << salary;
    }
};

int main() {
    Employee employees[5];  // Array of employee objects
    fstream file;
    int i, n;

    file.open("input.txt", ios::out);  // Create and open file for writing

    cout << "\nHow many employee records do you want to store? ";
    cin >> n;

    cout << "\nEnter information of employees (Enter name, emp_id, salary):\n";
    for (i = 0; i < n; i++) {
        cout << "\nEnter information for employee " << (i + 1) << ":";
        employees[i].accept();  // Accept input from user
        file.write((char *)&employees[i], sizeof(employees[i]));  // Write employee data to file
    }

    file.close();  // Close the file after writing

    file.open("input.txt", ios::in);  // Open the file for reading

    cout << "\nInformation of employees is as follows:\n";
    for (i = 0; i < n; i++) {
        file.read((char*)&employees[i], sizeof(employees[i]));  // Read employee data from file
        employees[i].display();  // Display employee data
    }

    file.close();  // Close the file after reading

    return 0;
}
