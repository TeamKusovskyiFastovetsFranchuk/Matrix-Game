#ifndef TASK_101_120_H
#define TASK_101_120_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string task_101(string &input) {
	int coord[5];
	int ind = 0;
	int l = input.length();
	string s = "";
	for (int i = 0; i < l; ++i) {
		if (input[i] == '{') {
			continue;
		}
		if (input[i] == '}') {
			if (i + 1 == l) {
				coord[ind] = stoi(s);
				break;
			} else {
				coord[ind] = stoi(s);
				ind++;
				s = "";
				i++;
				continue;
			}
		}
		if (input[i] == ',') {
			coord[ind] = stoi(s);
			ind++;
			s = "";
		} else {
			s += input[i];
		}
	}
	return to_string((coord[0] * coord[2]) + (coord[1] * coord[3]) == 0 ? 1 : 0);
}
#endif // TASK_101_120_H
