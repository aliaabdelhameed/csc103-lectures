#include <iostream>
using std::cout;
using std::endl;

void f(int n) {
	if (n == 0) {
		cout << 0 << " ";
		return;
	}
	f(n-1);
	cout << n << " ";
	/* TODO: make sure you understand the output from this.
	 * also swap the above lines, and make sure that output
	 * makes sense as well */
}

/* TODO: write down the other examples from lecture */
int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

/* TODO: practice proving things by mathematical induction. */

int main(void) {
	f(4);
	cout << "\n";

	cout << factorial(5) << endl;
	return 0;
}
