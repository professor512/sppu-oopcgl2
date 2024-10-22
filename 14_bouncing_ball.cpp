/*
Write C++ program to generate Bouncing ball. Apply the concept of polymorphism.
*/

#include <iostream>
#include <cstdlib>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int x, y, flag = 0;

    initgraph(&gd, &gm, NULL); // Initialize graphics mode

    // Get mid position in the x-axis and set initial y position
    x = getmaxx() / 2;
    y = 30;

    while (true) {
        // Change direction when hitting the top or bottom of the window
        if (y >= getmaxy() - 30 || y <= 30) {
            flag = !flag;
        }

        // Draw the red circle
        setcolor(RED);
        circle(x, y, 30);  // Draw circle
        floodfill(x, y, RED); // Fill circle

        // Delay for 50 milliseconds
        delay(50);
        
        // Clear the screen for the next frame
        cleardevice();

        // Move the circle up or down
        if (flag) {
            y += 5; // Move down
        } else {
            y -= 5; // Move up
        }
    }

    // Wait before closing (this line will never be reached in the infinite loop)
    delay(5000);
    closegraph(); // Close graphics mode
    return 0;
}
