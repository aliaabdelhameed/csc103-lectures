#include <iostream>
using std::cin;
#include <cstdio>

void dangerzone();

int main()
{
	/* dynamically allocate an int: */
	int* p = new int; /* this integer will NOT be on the runtime stack. */
	/* what is the 'new'??  The new operator does the following:
	 * 1. requests a block of memory (goes through libc; might involve a syscall).
	 * 2. marks the memory as being in use by your program.
	 * 3. gives you a pointer to the newly allocated block of memory.
	 * */
	/* store 17 in it: */
	*p = 17;
	/* give it a more convenient name if you want: */
	int& x = *p; /* this is called *aliasing* */
	printf("x == %i\n",x);
	printf("testing danger zone...  (!!!)\n");
	dangerzone();
	return 0;
}

/* to illustrate the potential badness of static arrays: */
void dangerzone() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int A[10];
	for (size_t i = 0; i <= 17; i++) {
		A[i] = i;
	}
	printf("g == %i\n",g);
	printf("f == %i\n",f);
	printf("e == %i\n",e);
	printf("d == %i\n",d);
	printf("c == %i\n",c);
	printf("b == %i\n",b);
	printf("a == %i\n",a);
	if (g != 0) printf("WTF?!?!?\n");
}

/* TODO: review the notes and see why danger zone does what it does. */
/* NOTE: can you see why g is set to 11 and not 10?  Hint: there is
 * another local variable on the stack before A.  (However, there are
 * other factors that can affect this as well.) */
/* NOTE: In the diagrams of the runtime stack in class, I left out
 * one piece of information -- storage for the return value.  This is
 * usually between the local variables and the return address.  However,
 * on x86_64, integer return values are usually passed via registers. */
