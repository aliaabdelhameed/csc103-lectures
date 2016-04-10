#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <set>
using std::set;
#include <vector>
using std::vector;

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
	if (b < 1) // assuming b has to be positive or 0 to compute a^b
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
	
	if (x < A[mid])
		return binarySearch(A, mid, x); 
		// lower half of the array, not including mid
	else if (x > A[mid])
		return binarySearch(A + mid + 1, size - mid - 1, x);
		// upper half of the array, not including mid
	else // x == A[mid], x is found in A
		return true;
}

/* TODO: try to write the "memoized" version of fibonacci */

int fibonacci(int n, map<int,int>& M) {
	// if the nth number is already in M, just return it
	if (M.find(n) != M.end())
		return M[n];
	else {
		int r;
		if (n < 2)	// n == 0 || n == 1
			r = n;
		else
			// r is the sum of the previous two fib numbers
			r = fibonacci(n-1,M) + fibonacci(n-2,M);
		M[n] = r;	// in the map, set the nth fib number equal to r
		return r;
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

/* POWER SET USING VECTOR OF VECTORS */
void printVector(vector<int> V) {
	cout << "{ ";
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << "}" << endl;
}

// S is the original set
// P is the power set, starts out as a set with the null set
vector<vector<int> > powerset(vector<int>& S, vector<vector<int> >& P) {
	if (S.size() == 0) { // set is empty
		return P;
	} else {
		/* int element = S[S.size() - 1]; // last element in S
		S.pop_back(); // deletes last element in S
		*/

		int element = S[0];
		S.erase(S.begin());

		vector<vector<int> > copy = P; // has at least the null set
		for (size_t i = 0; i < copy.size(); i++) {
			// add the element to each subset in the copy
			copy[i].push_back(element);
			//printVector(copy[i]);
			P.push_back(copy[i]); // now has sets with and without the element
							// twice as many sets as what it started out with
		}
		return powerset(S,P);
	}
}

/* POWER SET USING SET OF SETS */
void printSet(set<int> S) {
	cout << "{ ";
	for (set<int>::iterator i = S.begin(); i != S.end(); i++) {
		cout << *i << " ";
	}
	cout << "}" << endl;
}

// S is the original set
// P is the power set, starts out as a set with the null set
set<set<int> > powerset(set<int>& S, set<set<int> >& P) {
	if (S.size() == 0) {
		return P;
	} else {
		int element = (*S.begin()); // element is the first element of S
		S.erase(element);

		set<set<int> > copy = P;
		for (set<set<int> >::iterator i = copy.begin(); i != copy.end(); i++) {
			// i is an iterator pointing to each set in copy
			set<int> temp = (*i); // doing this because I can't do 
								// (*i).insert(*element); directly for some reason
			temp.insert(element); 
			P.insert(temp);
		}
		return powerset(S,P);
	}
}

int main() {
	/* TODO: write test code for your functions. */
	//printStuff(3);

	cout << "Print vertical stuff:" << endl;
	printVertically(3227);
	cout << "2^3 = " << exponent(2,3) << endl;
	cout << "2^10 = " << exponent(2,10) << endl;

	cout << "==================================" << endl;

	/* binary search test: */

	cout << "Binary search test:" << endl;
	cout << "Squares of numbers from 1 to 99 are in the array(true, returns 1).";
	cout << " All other numbers are not(false, returns 0)." << endl;
	int A[100];
	for (size_t i = 0; i < 100; i++) {
		A[i] = i*i; // array of squares of ints from 0 to 99
	}
	int x;
	while (cin >> x)
		//cout << search(A,100,x) << endl;
		cout << binarySearch(A,100,x) << endl;

	cout << "==================================" << endl;

	cout << "Fibonacci stuff:" << endl;
	map<int,int> M;
	for (int i = 0; i < 10; i++)
		cout << fibonacci(i,M) << " ";
	cout << endl;
#if 0
	cout << "==================================" << endl;

	cout << "Power set stuff with vectors:" << endl;

	vector<vector<int> > P;
	vector<int> empty;
	P.push_back(empty);

	vector<int> S;
	for (size_t i = 1; i <= 3; i++) {
		S.push_back(i);
	}

	cout << "Original set: ";
	printVector(S);

	powerset(S,P);

	cout << "Power set of S: " << endl;
	for (size_t i = 0; i < P.size(); i++) {
		printVector(P[i]);
	}
#else
	cout << "==================================" << endl;

	cout << "Power set stuff with sets:" << endl;

	set<set<int> > P;
	set<int> empty;
	P.insert(empty);

	set<int> S;
	for (size_t i = 1; i <= 3; i++) {
		S.insert(i);
	}

	cout << "Original set: ";
	printSet(S);

	powerset(S,P);

	cout << "Power set of S: " << endl;
	for (set<set<int> >::iterator i = P.begin(); i != P.end(); i++) {
		printSet(*i);
	}
#endif
	return 0;
}