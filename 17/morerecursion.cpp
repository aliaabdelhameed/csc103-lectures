#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<time.h>
#include <cstdlib> // for atol
#include <map>
using std::map;
#include <vector>
using std::vector;

// write the base 10 digits of n vertically to cout
// if n = 2358, want to print:
// 2
// 3
// 5
// 8
void printVertically(unsigned long n)
{
	/* remember the steps:
	 * 1. solve base case
	 * 2. break down problem in terms of itself:
	 *    "if I had a magic box that worked for
	 *    inputs of size n-1, how could I use it
	 *    to solve n??"
	 * */
	if (n < 10) {
		cout << n << endl;
		return;
	}
	/* 235|8
	 * ^^^ <-- n / 10.  we can get the 8
	 * via n % 10.  So, we can invoke the magic box on
	 * the left part (235), and then just print out
	 * the right part on our own. */
	printVertically(n/10);
	printVertically(n%10);
	//cout << n%10 << endl;
}
/* TODO: make sure you can write this on your own */

// compute nth term of fibonacci sequence
unsigned long fibonacciR(unsigned long n)
{
	/* base case: */
	if (n == 0 || n == 1) return 1;
	/* now pretend we have a magic solution for anything
	 * less than n.  Use it to solve the problem on input n. */
	return fibonacciR(n-1) + fibonacciR(n-2);
}
/* TODO: make sure you can draw the recursion tree for this and
 * that you understand why it is this so slow. */

/* TODO: write a good old-fashioned loop to compute the nth term
 * of thesequence: */
unsigned long fibonacci(unsigned long n)
{
	return 0; /* so it compiles... */
}

/* TODO: use what you learned about maps to make a *memoized* version
 * of the fibonacci function.  NOTE: a memoized function stores the
 * input/output pairs that it has already computed, and always checks
 * its database first to avoid re-computing an answer.  */
unsigned long fibonacci_memoized(int n, map<unsigned long,unsigned long>& answers)
{
	/* TODO: write this.  Just like the recursive one, but it remembers
	 * answers it already computed in the map. */
	return 0;
}

/* TODO: write code to compute the greatest common divisor of two integers
 * Do this with recursion -- no loops!  */
unsigned long gcd(unsigned long a, unsigned long b)
{
	return 1;
}

/* TODO: write the *extended* GCD algorithm, which returns gcd(a,b), but
 * also sets u and v such that ua + vb = gcd(a,b) Warning: this might take a
 * little bit of thinking (if you don't just look up the answer online).  Save
 * it for last. */
unsigned long gcdEx(unsigned long a, unsigned long b, long& u, long& v)
{
	return 0;
}

/* A few functions to test out what we have done: */

void basicTest()
{
	printVertically(235819);
}

void gcdTest()
{
	// TODO: modify this to test your extended gcd algorithm,
	// once you've written it, that is.
	unsigned long a,b,d;
	while(true) {
		cout << "Enter a,b: ";
		cin >> a;
		cin >> b;
		if(a==0 || b==0) return;
		d = gcd(a,b);
		cout << "The gcd is: " << d << endl;
	}
}

void fibonacciTest()
{
	long nterm;
	clock_t rstart,rend;
	clock_t start, end;

	//initialize the array for memoized fibonacci:
	map<unsigned long,unsigned long> F;
#define MEMOIZED 0

	while(cin >> nterm) {
		start = clock();
		cout << fibonacci(nterm) << endl;
		end = clock();

		rstart = clock();
#if MEMOIZED
		cout << endl << fibonacci_memoized(nterm,F) << endl;
#else
		cout << fibonacciR(nterm) << endl;
#endif
		rend = clock();

		/* print results: */
		cout << "The non-recursive function took "
			<< (end-start)/((double)CLOCKS_PER_SEC) << " seconds.\n";
#if MEMOIZED
		cout << "The memoized function took "
			<< (rend-rstart)/((double)CLOCKS_PER_SEC) << " seconds.\n";
#else
		cout << "The recursive function took "
			<< (rend-rstart)/((double)CLOCKS_PER_SEC) << " seconds.\n";
#endif
	}
}

// *DID YOU KNOW?*  You can treat functions as data types too (kinda).  Below,
// we declare an array of *function pointers*, and then use the argument from
// main(...) to select the right function to call.  Cool, right?
typedef void (*mainfn)(void); // function pointer datatype
mainfn mainFunctions[] =
{&basicTest, &gcdTest, &fibonacciTest};
// each element of the above array is a function that takes no arguments,
// and returns void.

int main(int argc, char** argv) {
	// Note: you should run main with command line arguments in order to select
	// the right function.  Calling "./morerecursion 1" would, for example call
	// the gcdTest() function.  If this is confusing, just comment it out and
	// call the function you want directly.
	mainFunctions[(argc>1)?atol(argv[1]):0]();
	return 0;
}
