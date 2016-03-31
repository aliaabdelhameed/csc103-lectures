#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>  // also known as an "associative array"
using std::map; // you can think of maps kind of like arrays,
				// but the indexes no longer have to be integers...
				// e.g., we could do A["a string"] = 100;

int main() {
	map<string,int> F;
	string s; /* hold input from stdin */
	while (cin >> s) F[s]++;
	/* that's all it takes to get frequency data. */
	/* how to go through a map???  Use an iterator: */
	for (map<string,int>::iterator i = F.begin(); i!=F.end(); i++)
		cout << (*i).first << " : " << (*i).second << endl;
	/*             ^^^^^^ "key"          ^^^^^ "value" */
	return 0;
	/* TODO: try to do this without using maps. */
	/* TODO: make an actual histogram, instead of just a freq. table. */
}
