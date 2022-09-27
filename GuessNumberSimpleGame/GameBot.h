#pragma once
#include <string>
#include <algorithm>
#include <map>
#include "Helper.h"

class GameBot {
public:
	GameBot();
	GameBot(int);
	GameBot(const std::string&);
	void getGuess(std::string&);
	Helper help(const std::string&) const;
	bool isCorrect(const std::string&) const;
private:
	std::string generated;
	std::map<char, int> controleSum;
	std::string Generator(int);
	std::map<char, int> Summurize(const std::string&) const;
};