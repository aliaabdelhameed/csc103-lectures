#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

vector<vector<int> > powerSet(vector<int>& V) {
	/* base case: */
	size_t n = V.size();
	if (n == 0) {
		/* return vector containing an empty vector: */
		// return vector<vector<int> >(vector<int>(),1);
		vector<int> empty;
		vector<vector<int> > r;
		r.push_back(empty);
		return r;
		/* here's the same thing using a nice constructor: */
		// return vector<vector<int> >(1,vector<int>());
	}
	/* general case: compute answer for V[0...size-2] store
	 * this in U.  Then add to U all of its own elements
	 * with a V[size-1] pushed to the back. */
	/* remove last element from V */
	int last = V[n-1];
	V.pop_back();
	vector<vector<int> > U = powerSet(V); /* NOTE: V is smaller now */
	size_t usize = U.size(); /* should be 2^{n-1} */
	for (size_t i = 0; i < usize; i++) {
		/* add last to U[i] */
		vector<int> T = U[i];
		T.push_back(last);
		U.push_back(T);
	}
	return U;
	/* TODO: erase this and write it from scratch. */
}

int main()
{
	/* run a test: */
	vector<int> V = {1,2,3};
	vector<vector<int> > P = powerSet(V);
	for (size_t i = 0; i < P.size(); i++) {
		cout << "[ ";
		for (size_t j = 0; j < P[i].size(); j++) {
			cout << P[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}

/* TODO: try to finish the extended gcd algorithm from the notes. */
