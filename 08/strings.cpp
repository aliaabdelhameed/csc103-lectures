/* strings.cpp
 * More examples working with strings...
 * */
#include <iostream>
using std::cin;
using std::cout; 
using std::endl;
#include <string>
using std::string;

/* TODO:  write a function that takes a string and a character
 * and returns the number of occurences of the character in the string.
 * Here's a plausible function header:
 * */
int countChars(const string& s, char c)
{
	return 0;
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

/* TODO: write a function that takes two strings and returns an
 * integer value indicating whether or not the first was a substring
 * of the second; the integer should be the index at which the string
 * was found, or -1 to indicate that the string was not found.
 * For example, findSubstr("def", "abcdef") would return 3.  (We did
 * most of this in lecture, but returned a bool...)
 * */
int substring(const string& s1, const string& s2) {
	return -1;
}

/* NOTE: there is a built-in string function for this (find(str,pos)).
 * TODO: try it out.
 * */

/* TODO: without looking at what we did in lecture, write a function that
 * takes a string by reference and reverses it.
 * */

int main() {
	/* TODO: write test code for all of the functions you wrote above */
	return 0;
}
