#ifndef TASK_161_180_H
#define TASK_161_180_H

#include <string>
#include <regex>
#include <cmath>
using std::string;
using std::stoi;
using std::to_string;

string task_161(string &input) {
	std::regex reg("\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\}");
	std::cmatch match;
	std::regex_match(input.c_str(), match, reg);


	int x1 = stoi(match[1]);
	int y1 = stoi(match[2]);

	int x2 = stoi(match[3]);
	int y2 = stoi(match[4]);

	int ans = abs(x1*y2 - x2*y1);

	return to_string(ans);
}

#endif // TASK_161_180_H
