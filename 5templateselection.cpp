// Write a function template for selection sort that inputs, sorts and outputs an integer array and 
#include<iostream>
using namespace std;

int n;
#define SIZE 10

template <class T>
void sel(T A[SIZE]) {
    int i, j, min;
    T temp;
    
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    int choice;
    char C[SIZE];
    int A[SIZE];
    float B[SIZE];
    int i;

    do {
        cout << "\n1. Integer";
        cout << "\n2. Float";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter Total Number of Integer Elements: ";
                cin >> n;
                cout << "\nEnter Integer Elements: ";
                for (i = 0; i < n; i++) {
                    cin >> A[i];
                }
                sel(A);
                break;
            }
            case 2: {
                cout << "\nEnter Total Number of Float Elements: ";
                cin >> n;
                cout << "\nEnter Float Elements: ";
                for (i = 0; i < n; i++) {
                    cin >> B[i];
                }
                sel(B);
                break;
            }
            case 3: {
                cout << "**********Program Exited Successfully**********" << endl;
                exit(0);
            }
            default: {
                cout << "\nInvalid Choice!";
                break;
            }
        }
    } while (choice != 3);

    return 0;
}
