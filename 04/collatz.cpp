/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Collatz conjecture: for all integers n, the following process
	 * will terminate in a finite number of steps:
	 *    if n == 1, stop;
	 *    if n is even, divide by 2;
	 *    if n is odd, multiply by 3 and add 1;
	 *    repeat using this new value of n.
	 * */

	int n;
	while (cin >> n) {
		/* test conjecture for n */
		while (n != 1) {
			cout << n << ":";
			if (n % 2 == 0) {
				n /= 2;
			} else {
				n = n*3 + 1;
			}
		}
		cout << "1\n";
	}


	return 0;
}

// vim:foldlevel=1
