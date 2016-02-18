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
	
	/* first read parameters P and Q: */
	cout << "Enter P and Q: ";
	int P,Q;
	cin >> P;
	cin >> Q;
	cout << "enter terms to compute: ";
	int n;
	while (cin >> n) {
		/* compute nth term of sequence. */
		if (n == 0) {
			cout << 0 << "\n";
		} else if (n == 1) {
			cout << 1 << "\n";
		} else {
			int a0 = 0; /* term two before current */
			int a1 = 1; /* term one before current */
			/* use n as a counter: */
			while (n > 1) {
				/* compute next term; update a0 and a1
				 * to maintain their meaning */
				int next = P*a1 - Q*a0;
				a0 = a1;
				a1 = next;
				n--;
			}
			cout << a1 << "\n";
		}
		/* TODO: delete this whole thing and write it from scratch. */
		/* TODO: while you're at it, simplify this.
		 * You don't need the "else if" block. */
	}

	return 0;
}

// vim:foldlevel=1
