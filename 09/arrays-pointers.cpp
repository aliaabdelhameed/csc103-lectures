// arrays and pointers.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int *x, int *y);
void circularShift(int A[], const int size, int shift);
void reverse(int A[], int startIndex, int endIndex);

int main() {
	/* ARRAYS: OVERVIEW
	 * Arrays in C/C++: kind of like a "dumb" version of std::vector.
	 * It has no concept of its size.  It has no fancy member functions
	 * like push_back, etc... */

	/* DECLARATION AND USE */
	int A[10]; /* A is an array of 10 integers. */
	for (size_t i = 0; i < 10; i++) {
		/* store list of cubes in the array: */
		A[i] = i*i*i; /* use the bracket operator to
		                  access elements, just like vectors */
	}

	/* WHAT'S *REALLY* IN AN ARRAY? */
	cout << "A == " << A << endl;
	/* A only contains a memory address!  This is the address
	 * of the first element A[0] */

	/* POINTERS: OVERVIEW
	 * They are just *variables that hold a memory address*.
	 * That's it!  Very simple!  E.g., our array A is a pointer.
	 * */

	/* POINTERS: MECHANICS
	 * What kinds of things might we want to do with pointers?
	 * Well the obvious ones are:
	 * 1.  declare them
	 * 2.  initialize them
	 * 3.  read to and write from the memory cell to which the pointer
	 *     points.
	 * */

	/* 1. declarations */
	int* p; /* declare a pointer.  Note the '*'.  Also acceptable
	           (and instructive) is to declare it as int *p;  In either
			   case, *p is of type int, and p is the address of that int. */
	#if 0
	/* NOTE: you could initialize the pointer by directly writing an address
	 * like this: */
	p = (int*) 4;
	/* and then try to write to that memory cell, like this: */
	*p = 17;
	/* TODO: change the above "#if 0" to "#if 1", compile, run, and take
	 * note of the error.  Sadly, it won't be the last time you see it... */
	#endif

	/* 2. initialization via "address-of"
	 * Much more useful than just writng a literal address, is storing the
	 * address of an existing variable.  This is done via the "address-of"
	 * operator, like so: */
	int x = 17;
	p = &x; /* read: "p gets the address of x." */
	/* NOTE: at this point, x and *p are synonyms.  Whatever happens to one
	 * will happen to the other: */
	cout << "p == " << p << "\tx == " << x << endl;

	/* 3. read/write using "dereference operator" */

	cout << "this is what's at the address stored in p: " << *p  << endl;
	(*p)++; // x becomes 18
	cout << "p == " << p << "\tx == " << x << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	/* TODO: think carefully, and see if you can predict the output of
	 * the following code before you run it: */
	int y = 23;
	int* q = &y;
	cout << "p == " << p << "\tx == " << x << endl;
	cout << "q == " << q << "\ty == " << y << endl;
	cout << "::: setting p = q;\n";
	p = q; // p points to where q is pointing, which is at y
	(*q)++; // y becomes 24
	cout << "p == " << p << "\tx == " << x << endl;
	cout << "q == " << q << "\ty == " << y << endl;
	cout << "*p == " << *p << "\tThis is the same as *q and y" << endl;

	/* Back to arrays for a moment:  what does the bracket notation (A[i])
	 * actually mean?  It is simply an addition of pointers, followed by
	 * a dereference: A[i] is the same as *(A+i) as it turns out.  There are
	 * even funny consequences of this -- instead of A[i], you can instead
	 * write i[A] (but I don't recommend it!) */
	char B[10];
	for (size_t i = 0; i < 10; i++) {
		B[i] = 'a' + i; // loops through and gets first 10 lowercase letters
	}
	
	// prints out contents of array B
	for (size_t i = 0; i < 10; i++) {
		cout << i << "[B] == " << i[B] << endl;
	}

	/* TODO: declare another pointer (say p2) to a character, initialize it
	 * just as we did before, and print out (p+i) and then (p2+i) for small
	 * values of i. Notice that the difference in memory addresses changes. */
	cout << "Declaring pointer p2 to a character: " << endl;
	char *p2;
	char c = 'j';
	p2 = &c;

	for (int i = 0; i < 5; i++) {
		cout << "(p+i) == " << (p+i) << '\t';
		cout << "(p2+i) == " << (p2+i) << endl;
	}

	cout << "Swapping two pointers: " << endl;
	int *p3, *p4;
	int num1 = 5, num2 = 10;
	p3 = &num1;
	p4 = &num2;
	cout << "p3 == " << p3 << "\tnum1 == " << num1 << "\t*p3 == " << *p3 << endl;
	cout << "p4 == " << p4 << "\tnum2 == " << num2 << "\t*p4 == " << *p4 << endl;

	swap(p3,p4);
	cout << "p3 == " << p3 << "\tnum1 == " << num1 << "\t*p3 == " << *p3 << endl;
	cout << "p4 == " << p4 << "\tnum2 == " << num2 << "\t*p4 == " << *p4 << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Circular Shift: " << endl;
	int size = 15;
	int C[size];
	for (size_t i = 0; i < size; i++) {
		C[i] = i;
	}

	for (size_t i = 0; i < size; i++) {
		cout << C[i] << " ";
	}
	cout << endl; 

	circularShift(C, size, 5);

	for (size_t i = 0; i < size; i++) {
		cout << C[i] << " ";
	}

	cout << endl;
	return 0;
}

/* TODO: write a function that returns void, and takes two
 * POINTERS to integers, and swaps the contents of those two
 * memory locations.  Note: part of this exercise is understanding
 * what I'm asking for...
 * */
void swap(int *x, int *y) {
	int temp;
	temp = *x; // temp has value x is pointing to
	*x = *y; // value x points to changes to value that y points to
	*y = temp; // y points to the value that x used to point to
}

/* TODO: Can you guess what the type of &p is, if the type of p is int* ? */
// &p is a type int* because it is the reference for p?

/* TODO: write a function that performs a "circular shift" on
 * an array of integers.  For example, if the input array
 * contained 0,1,2,3,4 and we shifted by 2, the new array would
 * contain 3,4,0,1,2.
 * NOTE: you can do this with *a constant amount of additional storage*.
 * That is, irrespective of the size of the array, your function should
 * allocate the same, fixed amount of storage.  No vectors.  No additional
 * arrays.  Just a few integers.  Try it!  (Kind of hard though.)
 * */

void circularShift(int A[], const int size, const int shift) {
	reverse(A,0,size - 1); // reverse the entire array
	reverse(A,0,shift - 1); // reverse elements up to the number you want to shift
	reverse(A,shift,size - 1); // reverse the rest of the array separately
}

// reverse the values in A, starting from the start index to end index, inclusively
void reverse(int A[], int start, int end) {
	for (size_t i = 0; i < (end - start + 1) / 2; i++) {
		int temp = A[start + i];
		A[start + i] = A[end - i];
		A[end - i] = temp;
	}
}

/*
void circularShift(int A[], const int size, const int shift) {
	int prevValue; // previous value
	
	for (int i = 0; i < shift; i++) { // shift i times
		
		for (int j = 0; j < size; j++) { // everything rotate one over
			if (j == 0) {
				prevValue = A[j]; // temp stores value in index 0
				A[j] = A[size - 1]; // take the last element, put it in index 1
			} else { // always happens after the if statement
				int temp2 = A[j];
				A[j] = prevValue; // shift the value on the right to the left
				prevValue = temp2;
			}
		}
	}
}*/
