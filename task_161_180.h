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


	int x1 = std::stoi(match[1]);
	int y1 = std::stoi(match[2]);

	int x2 = std::stoi(match[3]);
	int y2 = std::stoi(match[4]);

	int sqrX1 = x1 * x1;
	int sqrX2 = x2 * x2;
	int sqrY1 = y1 * y1;
	int sqrY2 = y2 * y2;
	double aLength = sqrt(sqrX1 + sqrY1);
	double bLength = sqrt(sqrX2 + sqrY2);

	double cosL = ((x1*x2 + y1*y2) / (aLength * bLength));

	double ans = bLength * aLength * sqrt((1 - (cosL * cosL)));

	return to_string(ans);
}

#endif // TASK_161_180_H
