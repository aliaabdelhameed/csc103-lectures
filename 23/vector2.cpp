/* implementation of home brew vector. */
#include "vector2.h"
#include <cassert>

vector2::vector2(size_t initCapacity) {
	size = 0;
	capacity = initCapacity;
	data = new int[capacity];
}

vector2::vector2(const vector2& V)
{
	size = V.size;
	capacity = V.capacity;
	//data = V.data;
	/* NO!  Above will end in disaster. TODO: make sure you understand why. */
	/* need to make a separate copy of V.data. */
	data = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		data[i] = V.data[i];
	}
}

vector2::~vector2() {
	/* free memory resources */
	delete [] data;
}

/* assignment operator.  there's a neat trick you can do to re-use the
 * copy constructor to do most of the work.  TODO: see if you can
 * explain why this works.  */
vector2& vector2::operator=(vector2 V)
{
	int* tmp = data;
	data = V.data;
	V.data = tmp;
	size = V.size;
	capacity = V.capacity;
	return (*this);
}

/* TODO: re-write the assignment operator using the following prototype: */
// vector2& operator=(const vector2& V);
/* the const by reference seems more plausible, but it will complicate
 * the implementation a good bit.  NOTE: you will have to modify the
 * header as well. */

/* push back: */
void vector2::push_back(int x) {
	/* check capacity: */
	if (size == capacity) /* out of space */ {
		capacity *= 2;
		/* allocate space: */
		int* newdata = new int[capacity];
		/* move old data to new array */
		for (size_t i = 0; i < size; i++) {
			newdata[i] = data[i];
		}
		/* delete old array: */
		delete [] data;
		data = newdata;
	}
	data[size++] = x;
	/* TODO: try to re-write this from scratch */
}

/* this should return the item we remove */
int vector2::pop_back() {
	/* make sure it isn't empty... */
	assert(size > 0);
	return data[--size];
	/* TODO: try to re-write this from scratch */
}
