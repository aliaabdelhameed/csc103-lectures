#include "rectangle.h"
#include <iostream>
using std::cout;
/* NOTE: single quotes instead of brackets:  this
 * controls the default search path when the compiler
 * is figuring out where rectangle.h lives.  Quotes
 * will instruct it to look in the current directory
 * first before moving on to /usr/include/... */

/* TODO: run `make clean` to erase the binaries, and then compile
 * this program manually using g++.  Run g++ -c first to produce
 * object files, and then run g++ again to link them into an executable. */

int main(void) {
	/*rectangle R;
	R.width = 8;
	R.height = 5;*/
	/* TODO: use the constructor to shorten the code above. */
	rectangle R(8,5);

	cout << "Area of R is " << R.area() << "\n";
	R.draw(); // NOTE: there's a hidden parameter in these function calls.
			  // the "this" pointer gives us access to whose member function
			  // is being called...
	/* TODO: test out the other functions.  Not exciting, but won't take long
	 * if you know what is going on.  */
	cout << "Perimeter of R is " << R.perimeter() << "\n";

	if (R.isSquare()) {
		cout << "R is a square\n";
	} else {
		cout << "R is not a square\n";
	}

	return 0;
}
