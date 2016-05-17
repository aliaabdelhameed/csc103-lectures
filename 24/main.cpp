#include "vector2.h"
#include <iostream>
using std::cout;

void fn(vector2 W) {
	cout << "oh no T.T\n";
	return;
} // <--- destructor for W called here.

/* this function illustrates why we need to write an
 * assignment operator. */
void fn2(vector2& W) {
	vector2 V;
	V = W;
	V.push_back(111);
	return;
} // <--- destructor for V called here.

int main()
{
	/* TODO: write test code for all the functions. */
	vector2 V;
	V.push_back(99);
	V.push_back(103);
	fn(V);
	fn2(V);
	return 0;
}
