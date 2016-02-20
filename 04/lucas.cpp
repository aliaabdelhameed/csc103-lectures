/* Lucas sequences. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Lucas sequences (of the first kind):
	 * U_n(P,Q) = P*U_{n-1}(P,Q) - Q*U_{n-2}(P,Q).
	 * */

		/* TODO: delete this whole thing and write it from scratch. */
		/* TODO: while you're at it, simplify this.
		 * You don't need the "else if" block. */

	
	int P,Q;
	cout << "Enter P and Q: ";
	cin >> P >> Q;
	cout << "Enter number of terms to compute: ";
	int n;
	while (cin >> n) {
		if (n == 0 || n == 1) {
			cout << n << endl;
		} else {
			int num1 = 0;
			int num2 = 1;
			while (n > 1) {
				int temp = num2 * P - num1 * Q;
				num1 = num2;
				num2 = temp;
				n--;
			}
			cout << num2 << endl;
		}
	}
	return 0;
}

// vim:foldlevel=1
