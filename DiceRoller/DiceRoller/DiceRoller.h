#pragma once
#include <string>
#include <random>

class DiceRoller {
public:
	DiceRoller(const std::string& command) {
		std::string::size_type find = command.find('d');
		int cnt = (find != 0) ? (std::stoi(std::string(command.begin(), command.begin() + find))) : (1);
		int bonus = 0;
		int value = 0;
		std::string::size_type tmp = find+1;
		find = command.find('+');
		if (find != std::string::npos) {
			value = std::stoi(std::string(command.begin() + tmp, command.begin() + find));
			bonus = std::stoi(std::string(command.begin() + find + 1, command.end()));
		}
		else {
			value = std::stoi(std::string(command.begin() + tmp, command.end()));
		}
		magic(cnt, value, bonus);
	}
	void magic(int cnt_of_dice, int value_of_dice, int bonus) {
		srand(time(0));
		result = 0;
		for (int i = 0; i != cnt_of_dice; ++i) {
			result += (rand() % value_of_dice) + 1;
		}
		result += bonus;
	}
	int getResult() const {
		return result;
	}

private:
	int result;
};