#ifndef TASK_201_220_H
#define TASK_201_220_H
#include <string>
#include <bitset>

using std::string;
using std::stoi;

string task_201_220(const string &str) {
	uint32_t A;
	uint32_t B;
	string num[2];
	int l = str.length();
	int id = 0;
	for (int i = 0; i < l; ++i) {
		if (str[i] == ',') {
			id++;
			continue;
		}
		num[id] += str[i];
	}
	A = stoi(num[0]);
	B = stoi(num[1]);
	std::bitset<32> bitsetA(A);
	std::bitset<8> bitsetB(B);
	string strA = bitsetA.to_string();
	string strB = bitsetB.to_string();
	int pos = strA.find(strB);
	if (pos != -1)
		pos = strA.length() - strB.length() - pos;
	return std::to_string(pos);
}
#endif // TASK_201_220_H
