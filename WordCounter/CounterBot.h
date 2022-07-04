#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

class CounterBot {
public:
	CounterBot(const std::string&);
	void getInfo();
	void compute();
	~CounterBot();
private:
	int counterOfWords;
	int counterOfChar;
	std::ifstream stream;
};