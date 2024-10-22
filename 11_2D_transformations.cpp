/*
Write C++ program to draw 2-D object and perform following basic
transformations: 1. Scaling 2. Translation 3. Rotation. Apply the concept of
operator overloading.
*/

#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class transform {
public:
    int m; // Number of edges
    int a[20][3]; // Input coordinates (including homogeneous coordinate)
    int c[20][3]; // Transformed coordinates
    void object();
    void accept();

    void operator*(float b[3][3]) { // Changed to 3x3 matrix for transformations
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) { // Change the loop to match 3 columns
                c[i][j] = 0; // Initialize c[i][j]
                for (int k = 0; k < 3; k++) { // Multiplying with 3x3 matrix
                    c[i][j] += (a[i][k] * b[k][j]);
                }
            }
        }
    }
};

void transform::object() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    line(300, 0, 300, 600); // Y-axis
    line(0, 300, 600, 300); // X-axis

    // Draw original object
    for (int i = 0; i < m - 1; i++) {
        line(300 + a[i][0], 300 - a[i][1], 300 + a[i + 1][0], 300 - a[i + 1][1]);
    }
    line(300 + a[0][0], 300 - a[0][1], 300 + a[m - 1][0], 300 - a[m - 1][1]);

    // Draw transformed object
    setcolor(RED); // Change color for transformed shape
    for (int i = 0; i < m - 1; i++) {
        line(300 + c[i][0], 300 - c[i][1], 300 + c[i + 1][0], 300 - c[i + 1][1]);
    }
    line(300 + c[0][0], 300 - c[0][1], 300 + c[m - 1][0], 300 - c[m - 1][1]);

    cout << "Press any key to continue...";
    getch();
    closegraph();
}

void transform::accept() {
    cout << "\nEnter the Number Of Edges: ";
    cin >> m;
    cout << "\nEnter The Coordinates:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j]; // Get x and y coordinates
        }
        a[i][2] = 1; // Set homogeneous coordinate to 1
    }
}

int main() {
    int ch, tx, ty, sx, sy;
    float deg, theta, b[3][3];
    transform t;
    t.accept();

    cout << "\nEnter your choice:";
    cout << "\n1. Translation"
         << "\n2. Scaling"
         << "\n3. Rotation\n";
    cin >> ch;

    switch (ch) {
    case 1:
        cout << "\nTRANSLATION OPERATION\n";
        cout << "Enter value for tx and ty: ";
        cin >> tx >> ty;
        b[0][0] = b[1][1] = b[2][2] = 1; // Set identity matrix
        b[0][1] = b[1][0] = 0; // Off-diagonal values
        b[2][0] = tx; // Translation in x
        b[2][1] = ty; // Translation in y
        t *b;
        t.object();
        break;

    case 2:
        cout << "\nSCALING OPERATION\n";
        cout << "Enter value for sx and sy: ";
        cin >> sx >> sy;
        b[0][0] = sx; // Scale x
        b[1][1] = sy; // Scale y
        b[0][1] = b[1][0] = 0; // Off-diagonal values
        b[2][0] = b[2][1] = 0; // Homogeneous coordinate
        b[2][2] = 1; // Last element in homogeneous coordinate
        t *b;
        t.object();
        break;

    case 3:
        cout << "\nROTATION OPERATION\n";
        cout << "Enter value for angle: ";
        cin >> deg;
        theta = deg * (3.14 / 180); // Corrected to 180 for degree to radian conversion
        b[0][0] = cos(theta);
        b[0][1] = sin(theta);
        b[1][0] = sin(-theta);
        b[1][1] = cos(theta);
        b[2][0] = b[2][1] = 0; // Set homogeneous coordinate
        b[2][2] = 1;
        t *b;
        t.object();
        break;

    default:
        cout << "\nInvalid choice";
    }

    getch();
    return 0;
}
