#pragma once
#include <string>
#include <random>
#include <iostream>

class DiceRoller {
public:
	DiceRoller(const std::string& command);
	void rollDice(int cnt_of_dice, int value_of_dice, int* result = nullptr);
	void magic(int cnt_of_dice, int value_of_dice, int bonus, char first_sigh);
	int getResult() const;
private:
	int result;
};