#include "vector2.h"
#include <cassert>
#include <algorithm>
using std::swap;

/* NOTE: if we define  */
// #define NDEBUG 1
/* then the assert() will disappear from the compiler input */

vector2::vector2(size_t initCapacity)
{
	size = 0;
	capacity = initCapacity;
	data = new int[capacity];
}

vector2::vector2(const vector2& V)
{
	size = V.size;
	capacity = V.capacity;
	// data = V.data;
	/* NO!  Above will end in disaster. TODO: make sure you understand why. */
	/* need to make a separate copy of V.data. */
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = V.data[i];
	}
}

vector2::~vector2()
{
	delete [] data;
}

/* here's a "classical" assignment operator */
/* NOTE: calling V = W; leads to the function call V.operator=(W); */
#if 0
vector2& vector2::operator=(const vector2& RHS) {
	/* goals: make (*this) a copy of V.  We'll need to
	 * delete the data of the LHS, make a new allocation
	 * of the right size, and then copy all the data. */

	/* first, have to check for "self-assignment".  That is,
	 * what if someone does V=V somehow? */
	if (this == &RHS) /* corresponds to V=V */
		return *this;
	/* clean up LHS memory: */
	delete[] data;
	/* now follow copy constructor more or less: */
	size = RHS.size;
	capacity = RHS.capacity;
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = RHS.data[i];
	}
	return *this;
}
#endif

/* fancy assignment operator.  uses neat trick to re-use
 * the copy constructor to do most of the work.  */
vector2& vector2::operator=(vector2 V)
{
	/* swap data pointers of *this and V: */
	swap(data,V.data);
	/* copy size and capacity from V */
	size = V.size;
	capacity = V.capacity;
	return (*this);
}

/* TODO: make sure you understand how the both versions of the
 * assignment operator are actually equivalent. */

int& vector2::operator[](size_t i) {
	/* TODO: write this.  Use the assert function like we did for pop_back */
	/* NOTE: we are returning by reference!  Why?? */
}

/* TODO: in case you didn't do these last time, erase push and pop and
 * write them from scratch. */
void vector2::push_back(int x) {
	if (size == capacity) {
		/* need to allocate more space. */
		capacity *= 2;
		int* olddata = data;
		data = new int[capacity];
		for (size_t i = 0; i < size; i++) {
			data[i] = olddata[i];
		}
		delete [] olddata;
	}
	data[size++] = x;
}
int vector2::pop_back() {
	assert(size);
	return data[--size];
}
