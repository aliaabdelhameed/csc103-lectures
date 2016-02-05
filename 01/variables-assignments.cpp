/* variables, datatypes, etc.  You can again compile this with
 *    $ g++ variables-assignments.cpp
 * and run it with
 *    $ ./a.out
 * */
#include <iostream>
/* NOTE: if it weren't for the "using" statement below,
 * we would have to type std::cout << ... all the time,
 * instead of just plain old  cout << ... */
using std::cout;

#include <string>
using std::string;

int main()
{
	/* declare a variable named x of type int: */
	int x; /* NOTE: "int" is the *datatype*
			  Every variable has a type!
			  Think of variables like containers,
			  and the datatype is like the shape
			  of the container. */
	/* how to write to x?  assignment statement: */
	x = 7;  /* (think of the data flowing to the left) */
	/* how to read from x?  Just use it in any expression: */
	cout << "x == " << x << "\n";
	/* arithmetic is pretty straightforward: */
	cout << "x + 13 == " << x + 13 << "\n";
	cout << "x / 14 == " << x / 14 << "\n";
	/* NOTE: above does integer division, so you lose the fractional part. */

	/* NOTE: numbers are interpreted literally (not as variables).
	 * Indeed, variables can't begin with a number.  TODO: uncomment the
	 * following line and try to compile: */
	// int 22x;

	/* if we want to keep the fractional part, we need
	 * a different datatype, like double or float. */
	double y = x / 14;
	cout << y << "\n"; /* still 0.  x/14 was still an integer
						  (0) and was converted to double afterward. */

	cout << "x / 14.0 == " << x / 14.0 << "\n";
	/* NOTE: type of 14.0 is not int.  Also note
	   that x will be "upgraded" for the division. */
	int z = x / 14.0;
	cout << z << "\n";

	/* how much space do our types take?? */
	cout << "double takes " << sizeof(double) << " bytes\n";
	cout << "float takes " << sizeof(float) << " bytes\n";
	cout << "int takes " << sizeof(int) << " bytes\n";
	cout << "long takes " << sizeof(long) << " bytes\n";

	/* NOTE: some basic laws of algebra do NOT hold up with messy
	 * floating point types.  Consider the cancellation law:
	 * a+x == b+x ==> a == b.  TODO: find an example in C++ where
	 * this doesn't work out. */

	/* Other non-number types: strings */
	string s = "hello there!\n";
	/* NOTE: to get the number of characters in the string,
	 * use the length() function: */
	cout << "length of s is: " << s.length() << "\n";
	/* NOTE: the sizeof(...) operator probably won't work the way
	 * you expect on strings.  */
	// cout << "size of s is: " << sizeof(s) << "\n";

	return 0;
	/* NOTE: the return 0 exits main, and thus ends our program.
	 * It gives the value 0 back to the shell to indicate a
	 * "successful" run.  Examples you can try in the shell:
	 * $ ./a.out && echo "success!"
	 * will print the success message if you return 0, but not
	 * if you return a nonzero value.  TODO: try it out.
	 * */
}

/* TODO:
 * 1. again, make sure you can compile this on the command line.
 * 2. play with it.  make a change that doesn't compile and try to
 *    make sense out of the resulting error messages.
 * 3  make sure you have streamlined the process of editing,
 *    compiling, and testing your program.
 * 4. play with git.  see the tutorial.  be sure to get
 *    familiar with 'git diff' and 'git log -p'. */

/* TODO: if you're feeling ambitious, try to write a program that reads 5
 * integers and prints out (a) the maximal value, and (b) the average. */

