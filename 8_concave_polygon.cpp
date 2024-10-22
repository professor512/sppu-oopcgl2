/*
Write C++ program to draw a concave polygon and fill it with desired color using fill
algorithm.
*/


#include <graphics.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

// Function to perform flood fill algorithm
void floodFill(int x, int y, int old_color, int new_color) {
    int current_color = getpixel(x, y); // Get the color of the current pixel
    if (current_color == old_color) {   // If the current pixel is of the old color
        delay(1);                       // Introduce a small delay
        putpixel(x, y, new_color);      // Set the pixel to the new color

        // Recursive calls to fill adjacent pixels
        floodFill(x + 1, y, old_color, new_color); // Right
        floodFill(x - 1, y, old_color, new_color); // Left
        floodFill(x, y + 1, old_color, new_color); // Down
        floodFill(x, y - 1, old_color, new_color); // Up
    }
}

int main() {
    int x1, y1, x2, y2, x3, y3, xavg, yavg;
    int gdriver = DETECT, gmode;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, NULL);

    // Input points for the triangle
    cout << "Enter the coordinates of the triangle vertices (x1, y1, x2, y2, x3, y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Draw the triangle
    setcolor(1); // Set line color to 1 (blue)
    line(x1, y1, x2, y2); // Line from (x1, y1) to (x2, y2)
    line(x2, y2, x3, y3); // Line from (x2, y2) to (x3, y3)
    line(x3, y3, x1, y1); // Line from (x3, y3) to (x1, y1)

    // Calculate the centroid of the triangle (average of the vertices)
    xavg = (x1 + x2 + x3) / 3;
    yavg = (y1 + y2 + y3) / 3;

    // Fill the triangle using flood fill algorithm
    floodFill(xavg, yavg, BLACK, RED); // Filling starting from the centroid

    // Wait for user input to close the graphics window
    getch();
    closegraph();

    return 0;
}
