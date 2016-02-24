#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

/* syntax:
 * datatype functionname(parameterlist) { c++ statements...}
 * think of f(x) from your calculus days... remember this notation?
 * f:R ---> R
 * Breaking it down, it says there is a function named f, which has domain R
 * and range R.  The C++ equivalent would be something like:
 * double f(double);
 * NOTE: thing above is called a "function prototype"
 */

/* example: x --> x*x + x
 * */
double f(double x) {
	/* you can use any statements to compute the return
	 * value.  Once you have it, just "return" it: */
	return (x*x)+x;
}

/* TERMINOLOGY: the variable used in the parameter
 * list (like x in fn2 or fn1) is called the *formal
 * parameter*.  When you actually make a call, like
 * fn(a) in main, the variable a is the *actual parameter*.
 * Again, for by value parameters, the formal parameter
 * is a COPY of the actual, and for by reference, it is
 * a SYNONYM for the actual.
 * */

/* Question: what is the relationship (in main memory)
 * of the actual parameter and formal parameter?  That
 * is, does the formal parameter have its own memory?
 * Or is it just another name for the actual parameter? */

double g(double x) {
	/* you can use any statements to compute the return
	 * value.  Once you have it, just "return" it: */
	double answer = (x*x)+x;
	x = 999;
	return answer;
	/* x will be a COPY of whatever is passed to the
	 * function.  Such parameters (x) are called "by value"
	 * parameters.
	 * */
}

/* We can also pass parameters BY REFERENCE.  Then the formal parameter will
 * be a synonym for the actual parameter (they live in the same memory). */
/* NOTE: the ampersand is the only difference from the function g above */
double h(double& x) {
	double answer = (x*x)+x;
	x = 999;
	return answer;
	/* x will be a COPY of whatever is passed to the
	 * function.  Such parameters (x) are called "by value"
	 * parameters.
	 * */
}

int max(int a, int b, int c);
double average(double a, double b, double c);
bool isPrime(int a);
void swap(int& a, int& b);
int nthFib1(int n);
int nthFib2(int n);

int main()
{
	/* HOW TO CALL? */
	cout << f(3) << "\n";

	/* BY VALUE VS BY REFERENCE */
	double a = 3;
	cout << "g(a) = " << g(a) << "\n";
	cout << "a = " << a << "\n";
	cout << "h(a) = " << h(a) << "\n";
	cout << "a = " << a << "\n";
	/* looks like x in g(...) was a COPY of a.  NOTE:
	 * you can make them share memory if you want...
	 * */

	cout << max(34, 20, 1) << endl;

	cout << average(2.5, 4.5, 6) << endl;
	
	cout << isPrime(2) << endl;
	cout << isPrime(5) << endl;
	cout << isPrime(9) << endl;

	int x = 5, y = 10;
	swap(x,y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	cout << nthFib1(5) << endl;
	cout << nthFib1(8) << endl;

	cout << nthFib2(5) << endl;
	cout << nthFib2(8) << endl;
	return 0;
}

/* TODO: write a function that takes 3 integers and returns
 * the maximal value */
int max(int a, int b, int c) {
	int max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	return max;
}

/* TODO: write a function that takes 3 doubles and returns the average value.
 * also write code in main to test it.  */
double average(double a, double b, double c) {
	double sum = a + b + c;
	return sum / 3;
}

/* TODO: write an isPrime function that takes an integer and returns a boolean
 * value indicating whether or not it is prime.  */
bool isPrime(int a) {
	if (a == 2) {
		return true;
	} else if (a == 1 || a % 2 == 0) {
		return false;
	} else {
		for (int i = 3; i <= sqrt(a); i++) {
			if (a % i == 0) {
				return false;
			}
		}
		return true;
	}
}

/* TODO: write a function that takes two integer parameters and swaps the
 * contents, i.e., if x=2 and y=5, then after calling swap(x,y), y=2 and x=5
 * Also write test code in main! */
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/* TODO: write a function that takes an integer n and returns the
 * nth term in the Fibonacci sequence. */

// method 1
int nthFib1(int n) {
	// starts with 0 and 1 in this case
	if (n == 1) { // 0 is the 1st term
		return 0;
	} else if (n == 2) { // 1 is the 2nd term
		return 1;
	} else {
		int first, second, next;
		first = 0;
		second = 1;
		for (int i = 3; i <= n; i++) {
			next = first + second;
			first = second; // shift the numbers down
			second = next; // update second with the sum of the previous two nums
		}
		return second;
	}
}

/* TODO: (WARNING: THIS IS NOT EASY. Only attempt this if you are bored.)
 * The previous exercise asked for you to compute the nth term of the
 * Fibonacci sequence.  Try to estimate approximately how many steps (number
 * of C++ statements, roughly) that your function takes to evaluate the input
 * n.  You will probably find that it is close to some constant multiple of n.
 * It turns out that there is a very clever way to do this in approximately
 * log(n) steps!  To find it, you'll probably need a hint or two to even get
 * started.  Ask me if you're interested.
 * */

// method 2: recursion
int nthFib2(int n) {
	if (n == 1) { // 0 is 1st term
		return 0;
	} else if (n == 2) { // 1 is 2nd term
		return 1;
	} else {
		return (nthFib2(n-1) + nthFib2(n-2));
	}
}
