// One more brute-force example.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <time.h>
#include <string>
using std::string;
#include <cstdio>
#include <string.h> // for strlen function on C-strings
#include <openssl/sha.h> // to compute sha1 hash.
// NOTE: you'll also need to link to libssl and libcrypto for this to work.

/* we'll use this horrible array to decode hex. */
unsigned char C['g'];
/* this will waste some space, but a pretty trivial amount in comparison
 * to all the other things that are going on.  */

int main(int argc, char *argv[])
{
	/* warm-up.  just print the hash of a constant string. */
	unsigned char testString[] = "hello world";
	unsigned char output[20];
	SHA1(testString,strlen((char*)testString),output);
	printf("SHA1(\"hello world\") == ");
	for (size_t i = 0; i < 20; i++) {
		printf("%02x",output[i]);
	}
	printf("\n");

	/* Now for the real challenge.  Read the hash of a (hopefully short)
	 * password from standard input, and then try to guess the password.
	 * Initially, we'll make some simplifying assumptions: let's assume
	 * that the passwords will be exactly 3 characters and only contain
	 * lower case letters for now.
	 * */

	// NOTE: in the ascii table, '0','1', etc. are consecutive, but
	// they are not actually equal to the integers 0,1,..  You can see
	// what the values actually are as follows:
	for (char i = '0'; i <= '9'; i++) {
		cout << i << " <---> " << (int)(i) << endl;
		/* note the typecast.  cout treats int's differently than char's,
		 * even though they have the exact same value.  */
	}

	/* First, setup our array for hex-decoding.  We'll map characters
	 * to their corresponding hex value.  */
	for (size_t i = 0; i < 10; i++) {
		C[i + '0'] = i;
	}
	for (size_t i = 0; i < 6; i++) {
		C[i + 'a'] = 10+i;
	}
	/* at this point, C[hexdigit] will give the right value. */
	/* TODO: fill in more of the table so that upper case A-F will
	 * also work for hexadecimal digits */

	/* read hash from stdin: */
	string hash;
	cin >> hash;

	//int count = 0;
	char pwd[4];
	pwd[3] = 0; // make it a null-terminated string.
	for (char i = 'a'; i <= 'z'; i++) {
		pwd[0] = i;
		for (char j = 'a'; j <= 'z'; j++) {
			pwd[1] = j;
			for (char k = 'a'; k <= 'z'; k++) {
				pwd[2] = k;
				SHA1((unsigned char*)pwd,3,output);
				#if 0
				/* if we wanted to print the hashes, we could
				 * do the following: */
				cout << pwd << ": ";
				for (size_t l = 0; l < 20; l++) {
					printf("%02x",output[l]);
				}
				cout << endl;
				/* NOTE: we can't just cout << output, since the bytes are
				 * *not* characters.  This will sabotage your terminal x_x */
				#endif
				// Now we need to check if hash == SHA1(pwd).  we would like to
				// do: "if (hash == output)" but it won't work.  hash contains
				// the hexadecimal chars, but output is the raw array of bytes.
				size_t l;
				for (l = 0; l < 20; l++) {
					if (C[(unsigned char)hash[2*l]]*16 +
							C[(unsigned char)hash[2*l+1]] != output[l])
						break;
				}
				if (l == 20) {
					cout << "Your password was " << i << j << k << endl;
					return 0;
				}
			}
		}
	}
	/* TODO: move the conversion of the string hash outside of the loop
	 * to save a little time. */

	return 0;
}

/* TODO: make this work for more general classes of passwords. Don't get
 * too ambitions, though -- I don't want you to melt your computer @_@ */
/* TODO: make this work *without* a bunch of *nested* for loops. (This is
 * a little harder.) */

/* NOTE: to test this out, use a command something like this:
 * echo -n "xyz" | sha1sum | ./brute-force
 * */
