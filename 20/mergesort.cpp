#include <iostream>
using std::cin;
using std::cout;

/* Goal of merge: merge L and R into L.  You can assume that
 * L has enough space for both arrays.  Use Aux for the auxillary
 * storage during the merge. */
void merge(int* L, int* R, int nL, int nR, int* Aux) {
	/* NOTE: Aux is the third pile of cards in our analogy */
	int iL=0,iR=0; /* top of the two input piles of cards */
	int iAux = 0; /* top of 3rd pile of cards */
	while (iL < nL && iR < nR) { /* both still have elements */
		if (L[iL] < R[iR]) {
			Aux[iAux++] = L[iL++];
		} else {
			Aux[iAux++] = R[iR++];
		}
	}
	/* at this point, one of the piles has run out.  Copy the rest of
	 * the leftover one. */
	while (iL < nL) Aux[iAux++] = L[iL++];
	while (iR < nR) Aux[iAux++] = R[iR++];
	for (int i = 0; i < nL + nR; i++)
		L[i] = Aux[i];
}

/* TODO: try to write the above from scratch. */

void mergeSort(int* A, int n /* == size of A */, int* Aux) {
	if (n < 2) return; /* base case. */
	int mid = n / 2;
	/* two subarrays are A[0..mid-1] and A[mid..n-1] */
	mergeSort(A,mid,Aux);
	mergeSort(A+mid,n-mid,Aux);
	merge(A,A+mid,mid,n-mid,Aux);
}

/* TODO: make sure you can draw the recursion tree. */

int main(void)
{
	/* TODO: write test code; fix any bugs. */
	int Aux[10];
	int A[10];
	/* fill up A */
	return 0;
}

/* TODO: try to write down the algorithm for permutations from lecture.
 * Also draw its recursion tree. */
