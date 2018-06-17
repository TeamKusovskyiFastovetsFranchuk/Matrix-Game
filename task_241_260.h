#ifndef TASK_241_260_H
#define TASK_241_260_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using std::string;
using std::to_string;
using std::vector;

string task_241(string &input) {
	vector <char> vc[2];
	vector <char> ans[5];
	int l = input.length();
	int ind = 0;
	for (int i = 0; i < l; ++i) {
		if (input[i] == ',') {
			ind++;
			continue;
		}
		vc[ind].push_back(input[i]);
	}

	std::sort(vc[0].begin(), vc[0].end());
	std::sort(vc[1].begin(), vc[1].end());

	std::set_union(vc[0].begin(), vc[0].end(), vc[1].begin(), vc[1].end(), std::back_inserter(ans[0]));
	std::set_intersection(vc[0].begin(), vc[0].end(), vc[1].begin(), vc[1].end(), std::back_inserter(ans[1]));
	std::set_difference(vc[0].begin(), vc[0].end(), vc[1].begin(), vc[1].end(), std::back_inserter(ans[2]));
	std::set_difference(vc[1].begin(), vc[1].end(), vc[0].begin(), vc[0].end(), std::back_inserter(ans[3]));

	string output = "";
	for (int j = 0; j < 4; ++j) {
		int k = ans[j].size();
		for (int i = 0; i < k; ++i) {
			output += ans[j][i];
		}
		if (j == 3) {
			break;
		}
		output += ',';
	}
	return output;
}

#endif // TASK_241_260_H
