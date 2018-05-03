#ifndef TASK_521_540_H
#define TASK_521_540_H

#include <string>
#include <set>
using std::string;
using std::stoi;
using std::to_string;

string task_521(string &input) {
	const int N = 100;
	const int maxCost = 999999;
	std::set <int> s;
	int g[N + 5][N + 5];
	int ans[N + 5];
	int l = input.length();
	int indI = 0;
	int indJ = 0;
	string num = "";
	for (int i = 0; i < l; ++i) {
		if (input[i] == ',') {
			g[indI][indJ] = stoi(num);
			num = "";
			indJ++;
			if (indJ == N) {
				indJ = 0;
				indI++;
			}
			continue;
		}
		num += input[i];
		if (i == l - 1) {
			g[indI][indJ] = stoi(num);
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
	out = to_string(ans[N - 1]);
	return out;
}

#endif // TASK_521_540_H
