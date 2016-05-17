/* simple vector of integers. */
#pragma once

#include <stddef.h>

class vector2 {
public:
	/* important stuff: *every* class that uses dynamic
	 * memory should implement the following: */
	/* (1) constructor and copy constructor. */
	vector2(size_t initCapacity = 16);
	vector2(const vector2& V); /* this is the copy constructor.
	    it will be called automatically when you pass vectors
		by value, as well as returning vectors by value, and
		possibly in other situations with intermediate rvalues. */
	/* (2) Destructor. This is to free any dynamically allocated
	 * memory when the object goes out of scope or is destroyed. */
	~vector2();
	/* (3) assignment operator */
	vector2& operator=(vector2 V);
	/* NOTE: return type is vector2 so we can do stuff like a = b = c; */

	/* member functions */
	void push_back(int);
	int pop_back();
	/* how to make V[i] syntax work for our class?  Define the
	 * operator for []: */
	int& operator[](size_t i);
private:
	/* a formalization of the *meaning* of these member variables
	 * is usually referred to as a "class invariant".
	 * Constructors will establish the class invariant,
	 * member functions assume the invariant is true, and then
	 * do some increment of work and *preserve* the class invariant.
	 * */
	size_t size; /* number of elements in vector */
	size_t capacity; /* size of data array */
	int* data; /* dynamically allocated storage for elements */
	/* NOTE: capacity and data are *linked* in that capacity
	 * should always contain the number of elements that've been
	 * allocated for the data array.  They have to be kept
	 * in sync.  Hence we make these guys *private*.  Changing
	 * them independently could result in an inconsistent state
	 * for the vector. */
};
