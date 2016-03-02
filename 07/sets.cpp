#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set> /* <-- new stuff. */
using std::set;
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
	for (set<int>::iterator i = s1.begin(); i != s1.end(); i++) {
		if (s2.find(*i) != s2.end()) /* found it! :D */
			I.insert(*i);
	}
	return I;
	/* TODO: if we swapped the roles of s1 and s2 above, we would
	 * still compute the intersection.  However, might it affect
	 * performance?  If so, modify this function to choose the roles
	 * dynamically (every time this is called) so as to maximize
	 * performance.
	 * */
}

/* TODO: write a function that returns the union of two sets */

/* TODO: emulate the insert function for the set, but for a vector.
 * That is, write a function that takes a vector (say of integers)
 * and a single integer x, and adds x to the vector *only if it was
 * not already present*. You can return a boolean indicating whether
 * or not x insertion took place. */

/* TODO: write a function that removes a value from a vector if it
 * is present.  It should take a vector and a value x, and remove
 * x if it is in the vector. NOTE: you don't have to preserve the
 * order of the other elements. */

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
	//setTest();
	//setTest2();
	intTest();
	return 0;
}
