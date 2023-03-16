#include "DiceRoller.h"

DiceRoller::DiceRoller(const std::string& command) {
	char first_sign = command[0];
	int cnt = 0;
	std::string::size_type find_d = 0;
	auto base = command.begin();
	if (isalnum(first_sign)) {
		first_sign = '0';
	}
	else {
		base += 1;
	}
	find_d = command.find('d');
	if (command[find_d] == (*base)) {
		cnt = 1;
	}
	else {
		cnt = (std::stoi(std::string(base, base + find_d)));
	}
	int bonus = 0;
	int value = 0;
	std::string::size_type tmp = find_d + 1;
	std::string temp_s;
	for (int i = tmp; i < command.size(); ++i) {
		if (isalnum(command[i])) {
			temp_s.push_back(command[i]);
		}
		else {
			find_d = i;
			break;
		}
	}
	value = std::stoi(temp_s);
	size_t tmp_it = command.find_last_of('-');
	int minus_bonus = ((tmp_it == std::string::npos) ? (-1) : (tmp_it));
	tmp_it = command.find_last_of('+');
	int plus_bonus = ((tmp_it == std::string::npos) ? (-1) : (tmp_it));
	if (minus_bonus != plus_bonus) {
		if (find_d >= minus_bonus) {
			find_d = minus_bonus;
		}
		else if (find_d >= plus_bonus) {
			find_d = plus_bonus;
		}
		else {
			find_d = std::string::npos;
		}
		if (find_d != std::string::npos) {
			bonus = std::stoi(std::string(command.begin() + find_d, command.end()));
			if (command[find_d] == '-') {
				bonus *= -1;
			}
		}
	}
	magic(cnt, value, bonus, first_sign);
}

void DiceRoller::rollDice(int cnt, int value, int* result) {
	if (!result) {
		result = &this->result;
	}
	for (int i = 0; i != cnt; ++i) {
		int t = (rand() % value) + 1;
		printf("Rolled: %d\n", t);
		//Add wait command
		*result += t;
	}
}

void DiceRoller::magic(int cnt_of_dice, int value_of_dice, int bonus, char first_sigh) {
	srand(time(0));
	int temp = 0;
	result = 0;
	rollDice(cnt_of_dice, value_of_dice);
	if (first_sigh != '0') {
		rollDice(cnt_of_dice, value_of_dice, &temp);
		if (bonus) {
			printf("Was rolled %d + %d and %d + %d \n", result, bonus, temp, bonus);
		}
		else {
			printf("Overall was rolled %d and %d \n", result, temp);
		}
		if (first_sigh == '+') {
			result = std::max(result, temp) + bonus;
		}
		else {
			result = std::min(result, temp) + bonus;
		}
	}
	else {
		printf("Was rolled %d + %d \n", result, bonus);
		result += bonus;
	}
}

int DiceRoller::getResult() const {
	return result;
}
