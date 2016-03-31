#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

int main() {
#if 0 // MAKING A HISTOGRAM WITH MAPS
	map<string,int> F;
	string s; /* hold input from stdin */
	while (cin >> s) F[s]++;
	/* that's all it takes to get frequency data. */
	/* how to go through a map???  Use an iterator: */
	for (map<string,int>::iterator i = F.begin(); i!=F.end(); i++) {
		//cout << (*i).first << " : " << (*i).second << endl;
	/*             ^^^^^^ "key"          ^^^^^ "value" */
		// PRINT OUT HISTOGRAM
		cout << (*i).first << " : ";
		for (int j = 0; j < (*i).second; j++) {
			cout << "#";
		}
		cout << endl;
	}
#else // COUNT FREQUENCY WITHOUT MAPS
	// using two vectors so the index of the keys and values correspond
	vector<string> keys;
	vector<int> values;
	string s;
	while (cin >> s) {
		int i;
		for (i = 0; i < keys.size(); i++) {
			if (keys[i] == s) {
				values[i]++;
				break;
			}
		}
		if (i == keys.size()) { // when you're out of the loop, if i == keys.size()
								// that means s was not found in the keys
			keys.push_back(s); 	// add the string to the keys value
			values.push_back(1);// add 1 to the values vector
		}
	}

	for (int j = 0; j < keys.size(); j++) {
		cout << keys[j] << " : ";
		for (int k = 0; k < values[j]; k++) {
			cout << "#";
		}
		cout << endl;
	}

#endif
	return 0;
	/* TODO: try to do this without using maps. */
	/* TODO: make an actual histogram, instead of just a freq. table. */
	

}
