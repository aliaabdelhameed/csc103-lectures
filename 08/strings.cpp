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
int countChars(const string& s, char c) {
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (char(s[i]) == c) {
			count++;
		}
	}
	return count;
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

 bool isPalindrome(const string& s) {
 	string reversed;
 	for (int i = s.length() - 1; i >= 0; i--) {
 		reversed += s[i];
 	}
 	return (s.compare(reversed) == 0);
 }

/* TODO: write a function that takes two strings and returns an
 * integer value indicating whether or not the first was a substring
 * of the second; the integer should be the index at which the string
 * was found, or -1 to indicate that the string was not found.
 * For example, findSubstr("def", "abcdef") would return 3.  (We did
 * most of this in lecture, but returned a bool...)
 * */
int substring(const string& s1, const string& s2) {
	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		for (int j = 0; j < s1.length(); j++) {
			if (s1[j] != s2[i + j]) { // if the entirety of s1
				break;				// is not found in s2
			} else if (j == s1.length() - 1) { // all of s1 is found
				return i; // this is where s1 starts in s2
			}
		}
	}
	return -1;
}

/* NOTE: there is a built-in string function for this (find(str,pos)).
 * TODO: try it out.
 * */

/* TODO: without looking at what we did in lecture, write a function that
 * takes a string by reference and reverses it.
 * */

 void reverse(string& s) {
 	for (int i = 0; i < s.length() / 2; i++) {
 		char temp = s[i];
 		s[i] = s[s.length() - 1 - i];
 		s[s.length() - 1 - i] = temp;
 	}
 }

int main() {
	/* TODO: write test code for all of the functions you wrote above */
	string s1 = "this is a test string";
	char c1 = ' ';
	char c2 = 'i';
	cout << "The string is: " << s1 << endl;
	cout << "' ' appears " << countChars(s1,c1) << " times in the string." << endl;
	cout << "'i' appears " << countChars(s1,c2) << " times in the string." << endl;

	/* ======================================== */

	string s2 = "hello";
	string s3 = "racecar";
	if (isPalindrome(s2)) {
		cout << s2 << " is a palindrome" << endl;
	} else {
		cout << s2 << " is not a palindrome" << endl;
	}
	if (isPalindrome(s3)) {
		cout << s3 << " is a palindrome" << endl;
	} else {
		cout << s3 << " is not a palindrome" << endl;
	}

	/* ======================================== */

	cout << substring("def", "abcdef") << endl;
	cout << substring("hello", "hello world") << endl;
	cout << substring("eyy","hello") << endl;

	string s4 = "abcdefefdefdef";
	string sub = "def";
	cout << s4.find(sub) << endl; // returns index of first appearance
	cout << s4.find(sub,5) << endl; // returns second appearance (starting at index 5)

	/* ======================================== */

	string s5 = "123456";
	cout << "String before: " << s5 << endl;
	reverse(s5);
	cout << "String after: " << s5 << endl;

	return 0;
}
