#include <vector>
using std::vector;
#include <cstdio>

/* TODO: write the 'growArray' function from the notes, along with
 * some test code. */

/* TODO: take note of how the vector is reallocating.  It will double the
 * capacity whenever it runs out of space.
 * TODO: make sure you understand why it doubles, as opposed to simply
 * incrementing the capacity by one every time it runs out of space.
 * */
int main()
{
	vector<int> V;
	size_t oldCapacity=-1;
	for (size_t i = 0; i < 17; i++) {
		printf("size:\t\t%lu\n",V.size());
		if (V.capacity() != oldCapacity) {
			oldCapacity = V.capacity();
			printf("capacity:\t%lu\n",V.capacity());
			/* NOTE: capacity is the size of the underlying
			 * array that the vector is managing. */
		}
		V.push_back(0);
	}
	return 0;
}
