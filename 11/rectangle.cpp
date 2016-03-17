/* rectangle.cpp
 * This is the implementation of our rectangle class.  Here we will
 * define *how* the rectangle does what it does.  (Under the hood stuff.)
 * */
#include "rectangle.h"
#include <iostream>
using std::cout;
using std::endl;

rectangle::rectangle(size_t w, size_t h) {
	// set our width and height from w,h:
	width = w;
	height = h;
}

size_t rectangle::area() {
	return height * width;
}

size_t rectangle::perimeter() {
	return 2 * (height + width);
}

bool rectangle::isSquare() {
	return (height == width);
}

/* TODO: remove the rectangle:: in front of draw
 * and understand what goes wrong. */
void rectangle::draw() {
	/* TODO: modify this to only print the edges,
	 * and pad the rows with spaces, since terminal
	 * characters are taller than they are wide.
	 * */
	/* draw with star characters... */
	for (size_t i = 0; i < height; i++) {
		cout << "* "; // left side will have height number of stars
		for (size_t j = 0; j < width - 2; j++) {
			if (i == 0 || i == height - 1) {
				cout << "* "; // prints out a row of stars if
							// it's the top or bottom of the rect
			} else {
				cout << "  ";
			}
		}
		cout << "*" << endl; // right side of rect
	}
}
