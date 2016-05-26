#include "vector2.h"

void fn(vector2 W) {
	W.push_back(111);
	return;
}
/* TODO: comment out the copy constructor (including the prototype
 * in the .h file) and see if you can figure out why calling this
 * function breaks things. */

int main()
{
	/* test out our vector. */
	vector2 V;
	V.push_back(99);
	V.push_back(103);
	fn(V);
	return 0;
}
