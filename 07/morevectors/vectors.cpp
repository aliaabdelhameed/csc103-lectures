/* Once again, some challenging vector exercises in case you missed them
 * the first time. */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cstdio>

/* NOTE: the capacity() function tells us how much space the vector
 * has available.  Call this function to watch how it grows: */
void test() {
	/* watch how the vector grows: */
	printf("testing capacity growth...\n");
	vector<int> v;
	for (size_t i = 0; i < 20; i++) {
		printf("%lu\n",v.capacity());
		v.push_back(i);
	}
}

int main()
{
	test();
	return 0;
}

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */

/* TODO: write a function that takes a vector and places the elements
 * in sorted order.  This is also kind of challenging. */

