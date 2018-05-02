#ifndef TASK_221_240_H
#define TASK_221_240_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string task221(string &input) {
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

#endif // TASK_221_240_H
