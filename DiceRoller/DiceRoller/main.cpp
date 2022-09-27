#include <iostream>
#include "DiceRoller.h"

int main() {
	while (true) {
		std::string command;
		std::cout << "Enter command in format ndx+numb (optional): ";
		std::cin >> command;
		if (command!="/e") {
			DiceRoller dr(command);
			std::cout << dr.getResult() << '\n';
		}
		else {
			std::cout << "Stoped rolling\n";
			break;
		}
	}
	return 0;
}