#ifndef TASK_501_520_H
#define TASK_501_520_H

#include <string>
#include <set>
using std::string;
using std::stoi;
using std::to_string;

string task_501(string &input) {
	const int N = 100;
	const int maxCost = 999999;
	std::set <int> s;
	int g[N + 5][N + 5];
	int ans[N + 5];
	int l = input.length();
	int indI = 0;
	int indJ = 0;
	for (int i = 0; i < l; i+=2) {
		if (input[i] == '0') {
			g[indI][indJ] = 0;
		} else {
			g[indI][indJ] = 1;
		}
		indJ++;
		if (indJ == N) {
			indJ = 0;
			indI++;
		}
	}
	ans[0] = 0;
	for (int i = 1; i < N; ++i) {
		ans[i] = maxCost;
	}
	s.insert(0);
	while (!s.empty()) {
		int k = *s.begin();
		s.erase(s.begin());
		for (int i = 0; i < N; ++i) {
			if (g[k][i] != 0) {
				if (ans[i] > ans[k] + g[k][i]) {
					ans[i] = ans[k] + g[k][i];
					s.insert(i);
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (ans[i] == maxCost) ans[i] = -1;
	}
	string out = "";
	for (int i = 0; i < N; ++i) {
		out += to_string(ans[i]);
		if (i != N - 1) out += ',';
	}
	return out;
}

#endif // TASK_501_520_H
