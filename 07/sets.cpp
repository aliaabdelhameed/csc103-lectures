#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set> /* <-- new stuff. */
using std::set;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <cstdio>

void setTest() {
	/* store perfect squares in a set and then do some searches. */
	set<int> s;
	for (int i = 0; i < 100; i++) {
		s.insert(i*i);
	}
	/* now run searches against it: */
	int n;
	while(cin >> n) {
		if(s.find(n) != s.end()) {
			cout << n << " was in the first 100 squares\n";
		} else {
			cout << n << " is not in the first 100 squares\n";
		}
	}
}

/* exercise: compute the intersection of two sets:
 * recall that the intersection of two sets is the set
 * consisting of the elements they have in common.  E.g.,
 * intersection of {2,3,4,5,6,7} and {1,2,4,7,11,44} is
 * {2,4,7}
 * */
set<int> intersect(const set<int>& s1, const set<int>& s2) {
	set<int> I; // will hold return value (the intersection).
	/* IDEA: go through every element in one of the sets,
	 * search for that element in the other set, and add
	 * to the intersection if you find it. */

	set<int> smallerSet, largerSet;
	if (s1.size() < s2.size()) {
		smallerSet = s1;
		largerSet = s2;
	} else { // doesn't matter if they are the same size
		smallerSet = s2;
		largerSet = s1;
	}

	for (set<int>::iterator i = smallerSet.begin(); i != smallerSet.end(); i++) {
		if (largerSet.find(*i) != largerSet.end()) /* found it! :D */
			I.insert(*i);
	}
	return I;
	/* TODO: if we swapped the roles of s1 and s2 above, we would
	 * still compute the intersection.  However, might it affect
	 * performance?  If so, modify this function to choose the roles
	 * dynamically (every time this is called) so as to maximize
	 * performance.
	 *
	 * Yes, choosing the set with fewer elements to loop through is
	 * more efficient because there are fewer elements to compare.
	 * */
}

/* TODO: write a function that returns the union of two sets */
/* go through both of the sets and add elements that are not
 * already in the union of the two sets.
 * if there is a repeat, skip it. */

set<int> getUnion(const set<int>& s1, const set<int>& s2) {
	set<int> U, other;

	// comparing the size of the two sets because
	// if U starts as being the larger set, there are fewer
	// elements to check
	if (s1.size() < s2.size()) { 
		U = s1;
		other = s2;
	} else { // doesn't matter if they are the same size
		U = s2;
		other = s1;
	}
	
	for (set<int>::iterator i = other.begin(); i != other.end(); i++) {
		if (U.find(*i) == U.end()) { // if i is not already in the union set
			U.insert(*i); // add i to the union
		}
	}
	return U;
}


/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */

bool insert(vector<int>& V, int x) {
	for (size_t i = 0; i < V.size(); i++) {
		if (V[i] == x) { // if x is already in V
			return false;
		}
	}
	V.push_back(x);
	return true;
}

/* TODO: write a function that removes a value from a vector if it
 * is present.  It should take a vector and a value x, and remove
 * x if it is in the vector. NOTE: you don't have to preserve the
 * order of the other elements. */

void remove(vector<int>& V, int x) {
	for (size_t i = 0; i < V.size(); i++) {
		if (V[i] == x) { // desired element to remove is found
			for (size_t j = i; j < V.size() - 1; j++) {
				// shift the elements down one
				V[j] = V[j + 1];
			}
			V.pop_back(); // to get rid of the last element
						// which was already shifted down
			break; // done once x is removed (elements are shifted down)
	
		}
	}
}

void intTest() {
	set<int> s1 = {2,3,4,5,6,7};
	set<int> s2 = {1,2,4,7,11,44};
	set<int> s3 = intersect(s1,s2);
	cout << "intersection contained: ";
	for (set<int>::iterator i = s3.begin(); i != s3.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

/* NOTE: sets do not store duplicates: */
void setTest2() {
	set<int> s;
	s.insert(5);
	cout << "size is " << s.size() << endl;
	s.insert(5);
	cout << "size is " << s.size() << endl;
}

int main(void)
{
	set<int> s1 = {2,3,4,5,6,7};
	set<int> s2 = {1,2,4,7,11,44};
	
	cout << "The union of the sets is: " << endl;
	for (int const& n : getUnion(s1,s2)) {
		cout << n << " ";
	}
	cout << endl;

	static std::vector<int> V = {2, 8, 1, 3, 5};
	insert(V,9);
	insert(V,2);
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << endl;

	remove(V,8);
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << endl;

	//setTest();
	//setTest2();
	intTest();
	return 0;
}
