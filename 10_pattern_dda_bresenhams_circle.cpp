/*
Write C++ program to draw the following pattern. Use DDA line and
Bresenham‘s circle drawing algorithm. Apply the concept of encapsulation.
*/

#include <iostream>
#include <graphics.h>
#include <stdlib.h>

using namespace std;

class dcircle {
private:
    int x0, y0;

public:
    dcircle() : x0(0), y0(0) {} // Constructor with member initializer list

    void setoff(int xx, int yy) {
        x0 = xx;
        y0 = yy;
    }

    void drawc(int x1, int y1, int r) {
        float d;
        int x, y;
        x = 0;
        y = r;
        d = 3 - 2 * r;

        do {
            putpixel(x1 + x0 + x, y0 + y - y1, WHITE);
            putpixel(x1 + x0 + y, y0 + x - y1, WHITE);
            putpixel(x1 + x0 + y, y0 - x - y1, WHITE);
            putpixel(x1 + x0 + x, y0 - y - y1, WHITE);
            putpixel(x1 + x0 - x, y0 - y - y1, WHITE);
            putpixel(x1 + x0 - y, y0 - x - y1, WHITE);
            putpixel(x1 + x0 - y, y0 + x - y1, WHITE);
            putpixel(x1 + x0 - x, y0 + y - y1, WHITE);

            if (d <= 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y = y - 1;
            }
            x = x + 1;
        } while (x < y);
    }
};

class pt {
protected:
    int xco, yco, color;

public:
    pt() : xco(0), yco(0), color(WHITE) {} // Constructor with member initializer list

    void setco(int x, int y) {
        xco = x;
        yco = y;
    }

    void setcolor(int c) {
        color = c;
    }

    void draw() {
        putpixel(xco, yco, color);
    }
};

class dline : public pt {
private:
    int x2, y2;

public:
    dline() : pt(), x2(0), y2(0) {} // Constructor with member initializer list

    void setline(int x, int y, int xx, int yy) {
        pt::setco(x, y);
        x2 = xx;
        y2 = yy;
    }

    void drawl(int colour) {
        float x, y, dx, dy, length;
        int i;
        pt::setcolor(colour);
        dx = abs(x2 - xco);
        dy = abs(y2 - yco);
        length = (dx >= dy) ? dx : dy; // Determine the length based on the greater change

        dx = (x2 - xco) / length;
        dy = (y2 - yco) / length;
        x = xco + 0.5;
        y = yco + 0.5;
        i = 1;

        while (i <= length) {
            pt::setco(x, y);
            pt::draw();
            x = x + dx;
            y = y + dy;
            i = i + 1;
        }
        pt::setco(x, y);
        pt::draw(); // Draw the last point
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x, y, r, x1, x2, y1, y2, n;

    dcircle c;

    // Input circle coordinates and radius
    cout << "\nEnter coordinates of centre of circle:\n";
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Enter the value of radius: ";
    cin >> r;

    // Draw coordinate axes
    int xmax = getmaxx();
    int ymax = getmaxy();
    int xmid = xmax / 2;
    int ymid = ymax / 2;

    setcolor(1); // Set color for axes
    line(xmid, 0, xmid, ymax); // Vertical line
    line(0, ymid, xmax, ymid); // Horizontal line

    setcolor(15); // Set color for circle
    c.setoff(xmid, ymid);
    c.drawc(x, y, r); // Draw circle

    // Input number of lines and their coordinates
    cout << "Enter Total Number of lines: ";
    cin >> n;

    dline l; // Create a line object
    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates of point x1: ";
        cin >> x1;
        cout << "Enter coordinates of point y1: ";
        cin >> y1;
        cout << "Enter coordinates of point x2: ";
        cin >> x2;
        cout << "Enter coordinates of point y2: ";
        cin >> y2;

        l.setline(x1 + xmid, ymid - y1, x2 + xmid, ymid - y2);
        l.drawl(15); // Draw line
    }

    // Input second circle coordinates and radius
    cout << "\nEnter coordinates of centre of circle:\n";
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Enter the value of radius: ";
    cin >> r;

    setcolor(5); // Set color for the second circle
    c.drawc(x, y, r); // Draw second circle

    getch();
    closegraph();
    return 0;
}
