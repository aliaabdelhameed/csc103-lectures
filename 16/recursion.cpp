#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// TODO: write a recursive function that prints the base 10 digits of n
// vertically to cout.  for example, printVertically(2358) would print
// 2
// 3
// 5
// 8
// Rules: you can't use any loops.  You can't use vectors or arrays.
// Just let the recursive function calls do the work for you.
void printVertically(unsigned long n) {
	// your code goes here.
	if (n < 10) {
		cout << n << endl;
		return;
	}
	printVertically(n / 10);
	cout << n % 10 << endl;
}

// TODO: write a recursive function to compute a^b (a to the b power)
int exponent(int a, int b) {
	if (b == 0)
		return 1;
	else
		return a * exponent(a,b-1);
}
/* binary search. */

/* TODO: erase this function and write it on your
 * own from scratch.  (Don't worry --  it will still
 * be in git). Alternatively, just rename this and
 * write your own version.  But don't cheat!  */

bool search(int* A, int size, int x) {
	/* base case: */
	if (size < 1) /* array is empty */
		return false;
	/* now do the recursive breakdown: solve the big problem
	 * in terms of magic recursive solutions to smaller problems */
	int mid = size / 2; /* pick mid-point to check against */
	/* NOTE:  the subarrays will always be STRICTLY smaller than size. */
	if (x > A[mid])
		/* search inside the subarray mid+1 .. size */
		return search(A+mid+1, size - mid - 1, x);
	/* NOTE: using pointer arithmetic to get the subarray */
	else if (A[mid] > x)
		/* search inside subarray 0 .. mid - 1 */
		return search(A,mid,x);
	else /* A[mid] == x */
		return true;
}

// A is the array of ordered integers
// size starts out as the size of A, later becomes the index that bounds
// where to check A
// x is the number we're trying to find
bool binarySearch(int* A, int size, int x) {
	if (size < 1)
		return false; // x not found
	int mid = size / 2; // because it's a binary search

	if (A[mid] == x) { // if this is what we're looking for
		return true;
	} else if (A[mid] > x) {
		
	} else if (A[mid] < x) {

	}
	
}

/* TODO: (this might be kind of challenging) write the power set
 * function we outlined in class.  NOTE: you can use vectors instead
 * of sets and just assume that the elements are unique.  NOTE: be
 * careful with the return type!  It will be a set of sets or vector
 * of vectors.  To avoid a syntax anomoly, you have to place a space
 * between the last set of '>' like this:
 * set<set<int> > P;
 *             ^ this space is important -_-
 * */

int main() {
	/* TODO: write test code for your functions. */
	//printStuff(3);
	printVertically(3227);
	cout << exponent(2,3) << endl;
	cout << exponent(2,10) << endl;
	/* binary search test: */
	/*
	int A[100];
	for (size_t i = 0; i < 100; i++) {
		A[i] = i*i;
	}
	int x;
	while (cin >> x)
		cout << search(A,100,x) << endl;
	return 0;
	*/
}

/* TODO: try to write the "memoized" version of fibonacci */
