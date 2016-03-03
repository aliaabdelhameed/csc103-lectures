#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <cstdio>

bool binary(const vector<int>& V, int x);
void sort( vector<int>& V);
// void sort(vector<string>& V);

int main() {

	vector<int> V;
	int n;
	cout << "Enter some integers: " << endl;
	while (cin >> n) {
		V.push_back(n);
	}
	sort(V);
	cout << "Sorted contents in the vector: " << endl;
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
	}
	
	if (binary(V,5)) {
		cout << "The vector has a 5!" << endl;
	}
	
	return 0;
}

void sort(vector<int>& V) {
	int min; // keeps track of min value
	size_t minIndex; // keeps track of where that min value is located
	for (size_t i = 0; i < V.size(); i++) {
		min = V[i];
		for (size_t j = i; j < V.size(); j++) {
			if (V[j] <= min) { // update with min if true
				min = V[j];
				minIndex = j;
			}
		}
		// swap after absolute min is found
		int temp = V[i];
		V[i] = min;
		V[minIndex] = temp;
	}
}

/*
 * couldn't get the sort for vector of strings to work :(
void sort(vector<string>& V) {
	string min;
	size_t minIndex;
	for (size_t i = 0; i < V.size(); i++) {
		min = V[i];
		for (size_t j = i + 1; j < V.size(); j++) {
			if (V[j].compare(min) <= 0) { // run through the vector
				min = V[j]; // update min with the lowest value
				minIndex = j; // saves the index of that number
			}
			// after the min is found, swap the values
			string temp = V[i];
			V[i] = min;
			V[minIndex] = temp;
		}
	}
}
*/


// the vector V should already be sorted
bool binary(const vector<int>& V, int x) {
	int leftBound, rightBound, currPos;
	leftBound = 0;
	rightBound = V.size() - 1;
	currPos = (leftBound + rightBound) / 2;

	while (currPos >= leftBound && currPos <= rightBound) {
		if (x < V[currPos]) {
			rightBound = currPos;
		} else if (x > V[currPos]) {
			leftBound = currPos;
		} else { // x == V[currPos]
			return true;
		}
		currPos = (leftBound + rightBound) / 2;
	}
	return false;
}
