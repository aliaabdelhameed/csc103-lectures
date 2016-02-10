#include <iostream>
using std::cout;
using std::cin;

int main() {
	int a, b, c, d, e;
	cout << "Input 5 integers (and enter after each one):\n";
	cin >> a >> b >> c >> d >> e;

	int temp1, temp2, max;
	if (a > b) {
		temp1 = a;
	} else {
		temp1 = b;
	}

	if (c > d) {
		temp2 = c;
	} else {
		temp2 = d;
	}
	
	if (temp1 > temp2) {
		max = temp1;
	} else {
		max = temp2;
	}

	if (e > max) {
		max = e;
	}

	double avg;
	avg = (a + b + c + d + e) / 5.0;

	cout << "Maximum: " << max << "\n";
	cout << "Average: " << avg << "\n"; 

	return 0;
}
