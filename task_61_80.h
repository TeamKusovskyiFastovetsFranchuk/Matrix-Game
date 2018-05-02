#ifndef TASK_61_80_H
#define TASK_61_80_H

#include <string>

std::string task_61(std::string &input) {
	int x = 0;
	int y = 0;
	int l = input.length();
	int ind = 0;
	for (int i = 0; i < l; ++i) {
		if (input[i] == 'S') {
			ind = i;
		}
	}
	for (int i = ind; i < l; ++i) {
		switch (input[i]) {
		case 'L': {
			x--;
			break;
		}
		case 'R': {
			x++;
			break;
		}
		case 'D': {
			y--;
			break;
		}
		case 'U': {
			y++;
			break;
		}
		case 'N': {
			break;
		}
		case 'X': {
			x = 0;
			break;
		}
		case 'Y': {
			y = 0;
			break;
		}
		case '*': {
			x *= 2;
			y *= 2;
			break;
		}
		case '/': {
			x /= 2;
			y /= 2;
			break;
		}
		case 'Q': {
			x *= x;
			y *= y;
			break;
		}
		case 'S': {
			x = 0;
			y = 0;
			break;
		}
		default: {
			x += int(input[i] - '0');
			y += int(input[i] - '0');
			break;
		}
		};
	}
	return std::to_string(x) + "," + std::to_string(y);
}


#endif // TASK_61_80_H
