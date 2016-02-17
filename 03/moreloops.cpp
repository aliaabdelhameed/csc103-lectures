/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main()
{
	/* a slight generalization of an earlier exercise:
	 * for integers n and k, determine the largest power
	 * of k that divides n. */
	cout << "enter two integers: ";
	int n,k;
	cin >> n >> k;
	/* now compute the largest power of k that still divides n */
	/* our process, in English: repeatedly "remove" factors of k from n,
	 * until there are none left; keep the number of removals in count.
	 * "loop invariants": each variable should have a clear
	 * meaning to you.  during each iteration of a loop
	 * you have to make sure this meaning is maintained.
	 * In this example:
	 * count === number of factors of k we've removed
	 * n     === original input with count k's removed
	 * k     === input from user -- shouldn't change.
	 * */
	int count = 0;
	while ( n % k == 0 /* k divides n */) {
		/* remove a factor of k and keep track of count. */
		n /= k; /* do a little work -- remove factor of k */
		count++; /* make sure *meaning* of count hasn't changed. */
	}
	cout << "n had " << count << " factors of " << k << "\n";


	/* exercise: brute force gcd.  Compute the greatest common
	 * divisor of n and k by an exhaustive search.  */
	/* in English:
	 * 1. start with smaller integer (this is an upper bound for the gcd)
	 * 2. work backwards until you find the first common divisor.
	 * */
	/* we'll reuse n and k above to store the input: */
	cout << "enter 2 integers for gcd thing: ";
	cin >> n>> k;
	int gcd; /* holds largest candidate gcd not yet tested. */
	if (n < k) gcd = n;
	else       gcd = k;
	while (true) {
		/* check if gcd is a common divisor: */
		if (n % gcd == 0 && k % gcd == 0)
			break; /* gcd contains the answer. */
		gcd--; /* preserve meaning of the variable. */
	}
	cout << "gcd was " << gcd << "\n";
	/* TODO: rewrite the above without while(true) (or while(1) etc...)
	 * and without a break statement.  Just replace the 'true' with
	 * the negation of the condition that breaks the loop! */
	cout << "Enter two integers to find the GCD: ";
	cin >> n >> k;
	if (n < k) {
		gcd = n;
	} else {
		gcd = k;
	}
	while (n % gcd != 0 || k % gcd != 0) {
		gcd--;
	}
	cout << "GCD is " << gcd << endl;

	/* exercise: brute force test for perfect cubes.  Check if
	 * n = k^3 for some integer k.  */
	/* in English: test all potential values of k.  Naively, k could
	 * be anywhere from 0...n */
	cout << "enter n for cube test: ";
	cin >> n;
	for (k=0; k <= n; k++) {
		/* is n == k^3? */
		if (n == k*k*k)
			break;
	}
	/* figure out why the loop ended.
	 * The break statement?  Or did the search fail? */
	
	if (k <= n)
		cout << k << " is the cube root of " << n << ".\n";
	else
		cout << n << " was not a cube.\n";

	/* TODO: write a loop that prints the sum of the first n odd cubes. */
	cout << "Enter an integer n and get the first n odd cubes: ";
	cin >> n;
	int x = 1;
	for (int i = 0; i < n; i++) {
		cout << x*x*x << endl;
		x += 2;
	}

	/* TODO: write code that gets an integer n from the user and prints out
	 * the n-th term of the fibonacci sequence. */
	cout << "Enter an integer n and get the nth term of the fibonacci sequence: ";
	cin >> n;
	int a,b,temp;
	a = 0;
	b = 1;
	if (n == 1) {
		cout << 0 << endl;
	} else if (n == 2) {
		cout << 1 << endl;
	} else {
		for (int i = 2; i < n; i++) {
			temp = a;
			a = b;
			b += temp;
		}
	}
	cout << "The " << n << "th fibonacci number is: " << b << endl;
	
	/* exercise: read an arbitrary list of integers and then print
	 * the max, min, and mean. */
	/* IDEA imagine someone is speaking these numbers to you, and
	 * all you have is a pencil and a tiny piece of paper.
	 * For max and min, just write the largest (resp. smallest)
	 * numbers you've seen *so far*.  At the end, they'll be the max and min.
	 * For the avarage, we just need the sum and the count of how many
	 * numbers there were.
	 * */
	int max,min,sum; /* we can compute mean from the sum and a count.
	                    meaning of variables:
					    max = largest we've seen so far.
					    min = smallest we've seen so far.
					    count = number of values read so far.
					    sum = sum so far */
	/* we'll reuse the count variable from earlier. */
	count = 0;
	sum = 0;
	cout << "enter integers for max/min/mean (end list with ctrl-d)\n";
	/* read one number first to set max and min: */
	cin >> n;
	max = min = sum = n;
	count++;
	/* NOTE: meaning of all our variables has been set!
	 * Now do one little increment of work in a loop, and
	 * make sure we maintain the meaning of these variables. */
	while (cin >> n) {
		if (n < min) min = n;
		if (n > max) max = n;
		count++;
		sum += n;
	}
	/* TODO: print answer.  Be sure to use a typecast in the division,
	 * else you'll lose the fractional part of the average. */
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Sum: " << sum << endl;
	cout << "Count: " << count << endl;
	cout << "Mean: " << double (sum) / count << endl;


	return 0;
}

// vim:foldlevel=1
