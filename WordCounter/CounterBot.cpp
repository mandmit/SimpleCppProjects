#include "CounterBot.h"


CounterBot::CounterBot(const std::string& path) {
	this->stream.open(path, std::ios::in);
	if (!this->stream)
	{
		std::stringstream ss;
		ss << "Coudn`t to open file with follow path: " << path;
		throw std::invalid_argument(ss.str());
	}
	this->compute();
}

void CounterBot::getInfo() {
	std::cout << "File has " << counterOfWords << " words and " << counterOfChar << " characters in total.\n";
}

void CounterBot::compute()
{
	char c;
	std::string str;
	while (this->stream >> c) {
		this->counterOfChar++;
	}
	this->stream.clear();
	this->stream.seekg(0);
	while (this->stream >> str) {
		this->counterOfWords++;
	}
}

CounterBot::~CounterBot()
{
	std::cout << "Successfully Cleard\n";
	this->stream.close();
}
