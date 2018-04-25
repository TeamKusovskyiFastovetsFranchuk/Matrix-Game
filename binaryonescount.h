#ifndef BINARYONESCOUNT_H
#define BINARYONESCOUNT_H

#include <string>
using std::string;
using std::stoi;
using std::to_string;

string onesCount(string input) {
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

#endif // BINARYONESCOUNT_H
