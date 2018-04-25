#ifndef ARRAY_H
#define ARRAY_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string arrayAddition(string input) {
	int l = input.length();
	string ans = "0123456789ABCDEF";
	for (int i = 0; i < l; ++i) {
		ans.erase(ans.find(input[i]), 1);
	}
	if (ans == "") {
		ans = "NULL";
	}
	return ans;
}

#endif // ARRAY_H
