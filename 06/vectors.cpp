// Introducing vectors; more on functions.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector> /* <--- new stuff */
using std::vector;
#include <cstdio>

/* exercise: write a function that takes a vector and searches
 * for a particular value, returning true iff it is found. */
bool search(const vector<string>& V, string x) {
	/* NOTE: the constant by reference parameter is a way
	 * to "fake" by value, but much faster (since compiler doesn't
	 * have to copy entire vector when this is called).  */
	for (size_t i = 0; i < V.size(); i++) {
		/* i ranges over valid indexes into V */
		if (x == V[i]) return true;
	}
	return false;
}

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
	/* exercise: read list of strings, print in reverse order. */
	vector<string> V; /* NOTE: vector is not by itself a datatype;
						 it is a machine that creates datatypes when
						 given any datatype as input. */
	// use vector<int> if you want a list of numbers instead.
	string s;
	int j = 0;
	while (cin >> s) {
		#if 1
		V.push_back(s);
#else
		/* TODO: change the 1 to a 0 above and make sure you understand
		 * what is going wrong.  See the test() function above...  */
		V[j++] = s;
		#endif
	}
	/* at this point we have all of stdin in memory. */
	/* now print in reverse order: */
	for (int i = V.size()-1; i >= 0; i--) {
		cout << V[i] << "\n";
	}

	if (search(V,"3")) cout << "3 was found.\n";

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

