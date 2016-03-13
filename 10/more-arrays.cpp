// more arrays.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <time.h>

int polyEval(int* a, size_t degree, int x);
int hornerEval(int a[], size_t degree, int x);
void randPerm(int* A, size_t n);
void printArray(int* A, size_t n);

int main() {
	int C[] = {3,2,1}; // x^2 + 2x + 3
	cout << "enter an integer: ";
	int x;
	cin >> x;
	cout << "f(" << x << ") = " << polyEval(C,2,x) << endl;
	cout << "f(" << x << ") = " << hornerEval(C,2,x) << endl;

	/* NOTE: you will need random numbers of course for the above exercise.
	 * Here is how you can get them: */
	// random number test:
	cout << "random number: " << rand() << endl;
	// the above number will always be the same, unless you set the seed
	// like this:
	srand(time(0)); // initialize the seed
	// now these will be different:
	cout << "more random numbers: " << rand() << endl << rand() << endl;

	cout << "Testing randPerm function: " << endl;
	int size = 10;
	int A[size];

	for (int i = 0; i < size; i++) {
		A[i] = i;
	}
	cout << "Original: ";
	printArray(A,size);
	randPerm(A,size);
	cout << "Random permutation: ";
	printArray(A,size);

	cout << endl;
	/* ================================================================== */
	cout << "Using randPerm on original {3 2 1} array: " << endl;
	randPerm(C,3);
	cout << "Random permutation: ";
	printArray(C,3);
	cout << "f(" << x << ") = " << hornerEval(C,2,x) << endl;
}

/* example: polynomial evaluation.
 * We'll represent a polynomial by its array of coefficients:
 * f(x) = a_0 + a_1x + a_2x^2..., we'll just store [a_0...]
 * to represent it.  Let's work over integers.  */
int polyEval(int* a, size_t degree, int x) {
	/* TODO: write this.  You can change the prototype to use
	 * vectors like we did in lecture.  Try to refer to tne notes
	 * as little as possible!
	 * */
	int sum = 0, lastxi = 1;
	for (size_t i = 0; i <= degree; i++) {
		sum += a[i] * lastxi;
		lastxi *= x;
	}
	return sum;
}

/* Example 2: Horner's rule for polynomial evaluation:
 * notice that the above loop took 2 multiplications
 * and one addition in each iteration.  Horner's rule
 * lets us compute the polynomial with ONE multiplication
 * and one addition per iteration of the loop.  */
int hornerEval(int a[], size_t degree, int x) {
	/* TODO: write this.  Try not to look at the notes much. */
	int sum = a[degree];
	for (size_t i = degree; i > 0; i--) {
		sum = sum * x + a[i - 1];
	}
	return sum;
}

/* TODO: write a function that takes an array, and its size, and applies
 * a random permutation to the array.  For random number generation, use
 * the rand function from the CRT.   I've updated the main() function to
 * show you an example, and added cstdlib + time.h to the includes.
 * NOTE: I want you to (under the assumption that rand() actually gives you
 * random numbers) produce a permutation which is *uniformly random* among
 * the set of all permutations.  HINT: think about how you count them.
 * There are n choices for the first element, n-1 for the second, and so on.
 * */
void randPerm(int* A, size_t n) {
	for (size_t i = 0; i < n; i++) {
		int temp = A[i];
		int randomIndex = (rand() % (n - i)) + i; // produces number from i to n
		A[i] = A[randomIndex]; // swap the values in the two positions
		A[randomIndex] = temp;
	}
}

void printArray(int* A, size_t n) {
	cout << "{ ";
	for (size_t i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << "}" << endl;
}