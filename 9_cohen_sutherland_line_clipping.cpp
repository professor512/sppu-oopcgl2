/*
Write C++ program to implement Cohen Southerland line clipping algorithm.
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
using namespace std;

class Coordinate {
public:
    int x, y;
    char code[4];
};

class Lineclip {
public:
    Coordinate PT;
    void drawWindow(); // Draws the clipping window
    void drawLine(Coordinate p1, Coordinate p2); // Draws a line
    Coordinate setCode(Coordinate p); // Sets the outcodes for a point
    int visibility(Coordinate p1, Coordinate p2); // Checks the visibility of the line
    Coordinate resetEndPoint(Coordinate p1, Coordinate p2); // Resets the endpoints if clipping is needed
};

int main() {
    Lineclip lc;
    int gd = DETECT, gm, v;
    Coordinate p1, p2, p3, p4;

    // Input for the coordinates of the line
    cout << "\nEnter x1 and y1: ";
    cin >> p1.x >> p1.y;
    cout << "\nEnter x2 and y2: ";
    cin >> p2.x >> p2.y;

    // Initialize the graphics window
    char driver[] = "VGA";
    initgraph(&gd, &gm, driver);

    // Draw window and original line
    lc.drawWindow();
    delay(2000);
    lc.drawLine(p1, p2);
    delay(2000);
    cleardevice(); // Clear the screen for the next drawing
    delay(2000);

    // Set the outcodes for the line points
    p1 = lc.setCode(p1);
    p2 = lc.setCode(p2);

    // Determine visibility of the line
    v = lc.visibility(p1, p2);
    delay(2000);

    // Perform the appropriate action based on visibility
    switch (v) {
        case 0: // Fully visible
            lc.drawWindow();
            delay(2000);
            lc.drawLine(p1, p2);
            break;
        case 1: // Fully invisible
            lc.drawWindow();
            delay(2000);
            break;
        case 2: // Partially visible (clipping needed)
            p3 = lc.resetEndPoint(p1, p2); // Recalculate endpoints
            p4 = lc.resetEndPoint(p2, p1);
            lc.drawWindow();
            delay(2000);
            lc.drawLine(p3, p4);
            break;
    }
    
    delay(2000);
    closegraph(); // Close the graphics window
    return 0;
}

// Function to draw the clipping window
void Lineclip::drawWindow() {
    rectangle(150, 100, 450, 350); // Rectangle boundary for clipping window
}

// Function to draw a line between two points
void Lineclip::drawLine(Coordinate p1, Coordinate p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

// Function to set the outcode for a given point
Coordinate Lineclip::setCode(Coordinate p) {
    Coordinate temp;
    temp.x = p.x;
    temp.y = p.y;

    // Top boundary
    temp.code[0] = (p.y < 100) ? '1' : '0';
    // Bottom boundary
    temp.code[1] = (p.y > 350) ? '1' : '0';
    // Right boundary
    temp.code[2] = (p.x > 450) ? '1' : '0';
    // Left boundary
    temp.code[3] = (p.x < 150) ? '1' : '0';

    return temp;
}

// Function to check the visibility of the line
int Lineclip::visibility(Coordinate p1, Coordinate p2) {
    int i, flag = 0;

    // Check for trivial acceptance
    for (i = 0; i < 4; i++) {
        if (p1.code[i] != '0' || p2.code[i] != '0') {
            flag = 1;
            break;
        }
    }
    if (flag == 0) return 0; // Fully visible

    // Check for trivial rejection
    for (i = 0; i < 4; i++) {
        if (p1.code[i] == '1' && p2.code[i] == '1') {
            return 1; // Fully invisible
        }
    }
    return 2; // Partially visible
}

// Function to calculate the new endpoint after clipping
Coordinate Lineclip::resetEndPoint(Coordinate p1, Coordinate p2) {
    Coordinate temp;
    int x, y;
    float m;

    // Left or right clipping
    if (p1.code[3] == '1') x = 150; // Left boundary
    if (p1.code[2] == '1') x = 450; // Right boundary
    if (p1.code[2] == '1' || p1.code[3] == '1') {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x); // Slope of the line
        y = p1.y + m * (x - p1.x); // Recalculate y using the line equation
        temp.x = x;
        temp.y = y;
        for (int i = 0; i < 4; i++) temp.code[i] = p1.code[i];
        if (temp.y <= 350 && temp.y >= 100) return temp;
    }

    // Top or bottom clipping
    if (p1.code[0] == '1') y = 100; // Top boundary
    if (p1.code[1] == '1') y = 350; // Bottom boundary
    if (p1.code[1] == '1' || p1.code[0] == '1') {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x); // Slope
        x = p1.x + (y - p1.y) / m; // Recalculate x using the line equation
        temp.x = x;
        temp.y = y;
        for (int i = 0; i < 4; i++) temp.code[i] = p1.code[i];
        return temp;
    }

    return p1;
}
