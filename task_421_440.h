#ifndef TASK_421_440_H
#define TASK_421_440_H
#include <string>
#include <algorithm>
#include <regex>
//#include <QStringList>
//#include <QVector>

std::string task_421_440(std::string str) {
	//	QStringList list = QString::fromStdString(str).split(",");

	std::regex r("(-?\\d+)");
	std::smatch res;
	std::vector<int> numbers;

	while (std::regex_search(str, res, r)) {
		numbers.push_back(std::stoi(res.str()));
		str = res.suffix();
	}

	//	int size = list.size();
	int size = numbers.size();
	//	QVector<int> numbers(size);
	//	for (int i = 0; i < size; ++i) {
	//		numbers[i] = list[i].toInt();
	//	}
	double avrX = static_cast<double> (std::accumulate(numbers.begin(), numbers.end(), 0)) / numbers.size();
	double summ = std::accumulate(numbers.begin(), numbers.end(), 0.0, [&avrX](double res, int x) {return res += pow((x - avrX), 2.0);});
	double medianDeviation = sqrt((1.0 / (size)) * summ);
	auto iter = std::unique(numbers.begin(), numbers.end());
	numbers.erase(iter, numbers.end());
	iter = std::remove_if(numbers.begin(), numbers.end(), [&medianDeviation, &avrX](int i){ return i > avrX + medianDeviation || i < avrX - medianDeviation;});
	numbers.erase(iter, numbers.end());
	std::sort(numbers.begin(), numbers.end());
	//	list.clear();
	//	for (int i = 0; i < numbers.size(); ++i) {
	//		list.push_back(QString::number(numbers[i]));
	//	}
	//	return list.join(",").toStdString();
	std::ostringstream out;
	for (auto i = numbers.begin(); i != numbers.end() - 1; ++i) {
		out << *i << ',';
	}
	out << numbers.back();
	return out.str();
}


#endif // TASK_421_440_H
