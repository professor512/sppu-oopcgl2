/* 
Write C++ program to generate snowflake using concept of fractals.
*/

#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class KochCurve {
public:
    void koch(int it, int x1, int y1, int x5, int y5) {
        int x2, y2, x3, y3, x4, y4;
        int dx, dy;

        if (it == 0) {
            line(x1, y1, x5, y5); // Draw the line if iterations are complete
        } else {
            delay(10); // Small delay for better visualization
            dx = (x5 - x1) / 3;
            dy = (y5 - y1) / 3;

            // Calculate the coordinates for the Koch curve points
            x2 = x1 + dx; // Point at 1/3
            y2 = y1 + dy; // Point at 1/3
            x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6); // Peak point
            y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);
            x4 = x1 + 2 * dx; // Point at 2/3
            y4 = y1 + 2 * dy; // Point at 2/3

            // Recursively draw the four segments
            koch(it - 1, x1, y1, x2, y2);
            koch(it - 1, x2, y2, x3, y3);
            koch(it - 1, x3, y3, x4, y4);
            koch(it - 1, x4, y4, x5, y5);
        }
    }
};

int main() {
    KochCurve k;
    int it;

    cout << "Enter Number Of Iterations: ";
    cin >> it;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Initialize the graphics system

    // Draw the Koch curve for the three sides of the triangle
    k.koch(it, 150, 20, 20, 280);  // Left side
    k.koch(it, 280, 280, 150, 20); // Right side
    k.koch(it, 20, 280, 280, 280); // Bottom side

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}
