/* rectangle.h
 * This is the header file for a simple class for storing rectangles.
 * Here we define *what* a rectangle does, but we do *not* say anything
 * about *how* it is done.  That is left to the implementation file.
 * The header file should tell other programmers everything they need
 * to know in order to use our rectangle class.
 * */

#pragma once
/* NOTE: the pragma once thing prevents someone from inadvertently
 * #include-ing this file twice, and thsu having multiple definitions
 * of everything here.  (Remember, #include is not very smart.) */

#include <cstdlib> // needed for size_t

/* NOTE: our rectangles will only have integer sides.  I like integers. */
class rectangle {
public:

	/* what data is required to represent a rectangle?
	 * width and height: */
	size_t width;
	size_t height;

	/* now, what might we want to do with a rectangle? */

	/* constructor: */
	/* TODO: remove default params and see if it compiles. */
	rectangle(size_t w=1, size_t h=1);
	/* the above function is called *automatically* whenever
	 * someone creates a new rectangle instance.  A few notes:
	 * 1. It has the same name as the name of the class.
	 * 2. It has NO RETURN TYPE
	 * 3. Note the "default arguments".  If no arguments are
	 *    supplied, w and h will be 1.
	 * */

	/* NOTE: no input parameters, since you have to have
	 * a rectangle to call this: e.g.,
	 * rectangle R;
	 * R.area();
	 * area() by itself doesn't make sense... */
	size_t area(); // return the area
	size_t perimeter(); // return the perimeter
	bool isSquare(); // is this rectangle actually a square?
	void draw(); // print a crappy representation to the console.

	/* here are the member variables that we need to store
	 * the information that determines a rectangle:
	 * */
private: // under the hood stuff
	// nothing is private for the moment.

}; // annoying syntax: you need a semicolon here.  Don't forget.
