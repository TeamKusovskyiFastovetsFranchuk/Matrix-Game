#ifndef TRIANGLEEXISTS_H
#define TRIANGLEEXISTS_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string isTriangle(string input) {
	int l = input.length();
	string s[3];
	int ind = 0;
	for (int i = 0; i < l; ++i) {
		if (input[i] == ',') {
			ind++;
		} else {
			s[ind] += input[i];
		}
	}
	int a = 0, b = 0, c = 0;
	a = stoi(s[0]);
	b = stoi(s[1]);
	c = stoi(s[2]);
	return to_string((a + b > c) && (a + c > b) && (b + c > a));
}

#endif // TRIANGLEEXISTS_H
