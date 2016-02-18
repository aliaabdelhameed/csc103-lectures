/* Flow of control:
 * Boolean expressions; if and while statements.
 * */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main()
{
	/* IF STATEMENTS */

	/* IDEA: execute a piece of code 0 or 1 times, conditioned upon a
	 * boolean expression.
	 * */
	cout << "do you think it is cold today? ";
	string input;
	cin >> input;
	if (input == "yes") {
		cout << "your a whimp. get over it.\n";
	} else if (input == "no") {
		cout << "I agree.  You should see siberia right now.\n";
	} else {
		cout << "Huh? o_O\n";
	}

	/* general form:
	 * if (<boolean expression>) {
	 *     statements...
	 * } else if (<boolean expression>) {
	 *     more statements...
	 * } else {
	 *     statements if all other cases failed...
	 * }
	 * NOTE: exactly ONE of the blocks of statements will be excuted: that
	 * of the first "match" (true expression), or the else at the end.
	 * */

	/* NOTE: TWO equals signs (==) are needed to test equality.
	 * Otherwise you'll end up doing assignment. */

	cout << "enter a number: ";
	int n;
	cin >> n;
	if ((n = 9)) {
		cout << "n was 9\n";
		/* NOTE: this will always happen!
		 * what's going on?  Three things you need to understand:
		 * 1. most every expression has a type and a value;
		 * 2. assignment statements take the value of the RHS
		 * 3. integers can be interpreted as booleans using the convention
		 *    that 0 is false, and everything else is true. */
	}
	/* TODO: write a corresponding example with n = 0, which will never
	 * print the message, even if if n really was 0. */
	cout << "Enter a number: ";
	int n2;
	cin >> n2;
	if ((n2 = 0)) {
		cout << "n2 was 0\n";
	}

	/* TODO: remove the extra parenthesis around the assignment and
	 * make sure compiler warning makes sense. */

	/* Boolean expressions: expressions that can evaluate to either
	 * true or false.  For example, x == 3, or response != "yes".
	 * other (binary) boolean operators:
	 * ==
	 * !=
	 * <
	 * >
	 * <=
	 * >=
	 * Furthermore, we have the following operators on booleans:
	 * && -- this gives the logical "and"
	 * || -- this gives the logical "or"
	 * !  -- this gives the logical negation
	 * */


	/* LOOPS */

	/* general form:
	 * while (<boolean expression>) {
	 *    statements to do while expression is true...
	 * }
	 * */

	#if 0
	while (true) {
		cout << "it's cold @_@ ";
		/* infinite loop!!! watch out for this.  Hit Ctrl-c if
		 * it happens to you. */
	}
	#endif

	/* Try to print a list of the first 10 perfect squares:
	 * (1,4,9,16,25,...) */
	int i; /* what's in i right now?  you have no idea!
	          uninitialized variables have unpredictable contents. */
	i = 1;
	while (i <= 10) {
		/* print out square of some integer. */
		cout << i*i << "\n";
		i++; // equivalent to i = i + 1;
	}
	cout << "value of i is " << i << "\n";
	/* TODO: make sure you know why this is 11. */

	/* NOTE: The above pattern of:
	 * 1. initialize some counter kind of variable
	 * 2. loop on the counter being below / above a bound
	 * 3. increment counter at the end of the loop
	 * is very common.  For these kinds of patterns, there is
	 * another loop that may be more suitable: the for loop.
	 * */

	for (int i = 1; i <= 10; i++) {
		cout << i*i << "\n";
	}

	/* Problem: given an integer n, find exponent of the
	 * largest power of two that divides n.  Example:
	 * if n = r*8 with r odd, then you should output 3
	 * since 8 = 2^3.  (You are just recovering the exponent
	 * of the 2 in the number's factorization into primes.)
	 * */
	/* IDEA: keep on dividing n by two until we can't,
	 * and keep track of how many times it worked. */
	cout << "enter an integer: ";
	int x; // store input.
	cin >> x;
	int count = 0;
	while ( x % 2 == 0 /* while x is even */ ) {
		/* divide x by 2 and increment count. */
		x /= 2; // same as x = x/2;
		count++;
	}
	cout << "number of 2's was " << count << "\n";

	/* TODO: write a piece of code that reads integers from standard
	 * input until a negative integer is entered, and then computes
	 * the minimal value, the maximal value, and the average value
	 * of all the (non-negative) integers that were entered.
	 * (Hint: you don't have to store all those numbers at once... )*/
	cout << "Enter some integers. Stop by entering a negative: ";
	int min, max, sum;
	min = max = sum = count = 0;
	cin >> n;
	min = max = n;
	while (cin >> n) {
		if (n >= 0) { // n is positive
			if (n < min) {
				min = n;
			} 
			if (n > max) {
				max = n;
			}
			sum += n;
			count++;
		} else { // n is negative
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
			cout << "Average: " << double(sum) / count << endl;
			break;
		}
	}

	return 0;
}

/* TODO: compile this via the makefile instead of typing out the g++
 * commands yourself.  */

// vim:foldlevel=1
