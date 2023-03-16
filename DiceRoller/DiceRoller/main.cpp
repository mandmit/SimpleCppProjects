#include <iostream>
#include "DiceRoller.h"

int main() {
	while (true) {
		std::string command;
		std::cout << "Enter command in format [+ or -][1-9]d(1-100)[+ or - (1-100)] where [ ] - is optional fields\nExit - /e :";
		std::cin >> command;
		if (command!="/e") {
			DiceRoller dr(command);
			std::cout << "Result : " << dr.getResult() << '\n';
		}
		else {
			std::cout << "Rolling was stopped\n";
			break;
		}
	}
	return 0;
}