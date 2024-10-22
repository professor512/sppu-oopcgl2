/* 
Write OpenGL Program to draw Sunrise and Sun Set.
*/

#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Initialize graphics mode

    int midx = getmaxx() / 2; // Get the middle x-coordinate of the window
    int midy = getmaxy() / 2; // Get the middle y-coordinate of the window
    int r = 10; // Initial radius

    // Loop to draw and animate the arc
    while (r <= 50) {
        cleardevice(); // Clear the screen

        setcolor(WHITE);
        // Draw the outline of a structure (like a tent or roof)
        line(0, 310, 160, 150);
        line(160, 150, 320, 310);
        line(320, 310, 480, 150);
        line(480, 150, 640, 310);
        line(0, 310, 640, 310);

        // Draw an arc with increasing radius
        arc(midx, 310, 225, 133, r);
        
        // Fill the area inside the arc
        floodfill(midx, 300, WHITE);

        // Additional fills when radius is greater than 20
        if (r > 20) {
            setcolor(7); // Set color to light gray
            floodfill(2, 2, WHITE); // Fill top left corner

            setcolor(6); // Set color to yellow
            floodfill(150, 250, WHITE); // Fill area near the left side
            floodfill(550, 250, WHITE); // Fill area near the right side

            setcolor(2); // Set color to green
            floodfill(2, 450, WHITE); // Fill bottom left corner
        }

        delay(50); // Delay to slow down the drawing
        r += 2; // Increase the radius
    }

    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}
