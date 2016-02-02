/* simple hello world program with voluminous comments.
 * To compile it into a binary program, simply run `g++ hello.cpp`
 * Then run `./a.out`
 * NOTE: save time by combining those commands into one:
 * `g++ hello.cpp && ./a.out`
 * Save even more time by using the up arrow to go through your
 * command history. */
#include <iostream> /* "iostream" is just a C++ file. the #include sticks
					   the contents here in your file upon compiling. 
					   iostream has some things to make reading and
					   writing to the screen easier. */
/* NOTE: stuff between slash-* ... *-slash are not read by
 * the compiler.  */
// NOTE: you can also write comments like this with "//" at the front.

/* stuff we need from iostream: */
using std::cout; /* this thing helps us write to the screen. */
/* NOTE: normal variable names are just letters numbers, and
 * maybe underscores.  The "std" above is like cout's last
 * name.  "cout" is the first name. */

int main() // <--- your programs will always start here at "main".
{
	cout << "Hello world.\n";
	/* TODO: what happens if you
	 * 1. put an actual newline instead of "\n"?
	 * 2. remove the quotes?
	 * 3. remove the semicolon at the end? 
	 * Try each of thse mistakes out and see what the compiler says. */
	return 0;
}

// vim:foldlevel=2
