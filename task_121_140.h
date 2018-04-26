#ifndef TASK_121_140_H
#define TASK_121_140_H
#include <string>
#include <QStringList>

std::string isComplantation(std::string str) {
	QStringList list = QString::fromStdString(str).replace(QRegExp("[,\\{\\}]"), " ").simplified().split(" ");
	return std::to_string(list[0].toInt() * list[4].toInt() * list[8].toInt()
	+ list[1].toInt() * list[5].toInt() * list[6].toInt()
	+ list[2].toInt() * list[3].toInt() * list[7].toInt()
	- list[2].toInt() * list[4].toInt() * list[6].toInt()
	- list[1].toInt() * list[3].toInt() * list[8].toInt()
	- list[0].toInt() * list[5].toInt() * list[7].toInt());
}


#endif // TASK_121_140_H
