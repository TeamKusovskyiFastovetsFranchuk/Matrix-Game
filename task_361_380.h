#ifndef TASK_361_380_H
#define TASK_361_380_H

#include <string>
#include <regex>
#include <cmath>
using std::string;
using std::stoi;
using std::to_string;

struct pt {
	int x, y;
};

inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  std::swap (a, b);
	if (c > d)  std::swap (c, d);
	return std::max(a,c) <= std::min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
	&& intersect_1 (a.y, b.y, c.y, d.y)
	&& area(a,b,c) * area(a,b,d) <= 0
	&& area(c,d,a) * area(c,d,b) <= 0;
}

string task_361(string &input) {
	std::regex reg("\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\},\\{(-?\\d+),(-?\\d+)\\}");
	std::cmatch match;
	std::regex_match(input.c_str(), match, reg);

	pt A;
	A.x = stoi(match[1]);
	A.y = stoi(match[2]);

	pt B;
	B.x = stoi(match[3]);
	B.y = stoi(match[4]);

	pt C;
	C.x = stoi(match[5]);
	C.y = stoi(match[6]);

	pt D;
	D.x = stoi(match[7]);
	D.y = stoi(match[8]);

	return to_string(intersect(A, B, C, D));
}
#endif // TASK_361_380_H
