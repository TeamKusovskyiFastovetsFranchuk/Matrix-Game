#ifndef TASK_181_200_H
#define TASK_181_200_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string task181(string &input) {
	int k = stoi(input);
	int ans = 0;
	while (k > 0) {
		if (k % 2 == 1) {
			ans++;
		}
		k /= 2;
	}
	return to_string(ans);
}

#endif // TASK_181_200_H
