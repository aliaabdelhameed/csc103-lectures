#include <iostream>
using std::cout;
#include <vector>
using std::vector;

vector<vector<int> > ksubsets(vector<int>& V, size_t k) {
	size_t n = V.size();
	if (k > n) { /* return an EMPTY vector */
		return vector<vector<int> >();
	}
	if (k == 0) {/* return vector containing empty vector */
		return vector<vector<int> >(1,vector<int>());
	}
	/* TODO: make sure you understand these base cases! */
	/* now the recursive breakdown... @_@ */
	int last = V[n - 1];
	V.pop_back(); /* now V has size n-1, so we can do recursive calls */
	vector<vector<int> > L = ksubsets(V,k); /* want all of these. */
	vector<vector<int> > R = ksubsets(V,k-1); /* add last to all these */
	for (size_t i = 0; i < R.size(); i++) {
		vector<int> T = R[i];
		T.push_back(last); /* add last element */
		L.push_back(T); /* add to L, which we'll later return. */
	}
	V.push_back(last); /* un-modify V I guess */
	return L;
	/* TODO: try to write this from scratch. */
}

int main()
{
	vector<int> V = {1,2,3,4};
	vector<vector<int> > K = ksubsets(V,2);
	for (size_t i = 0; i < K.size(); i++) {
		cout << "[ ";
		for (size_t j = 0; j < K[i].size(); j++) {
			cout << K[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}
