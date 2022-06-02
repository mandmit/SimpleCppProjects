#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

enum Difficult {
	Easy = 10,
	Seriosly = 100,
	Crazy = 400,
	Unbeliveble = 1000
};

int main() {
	char command = 'y';
	while (command == 'y') {
		std::cout << "\tWelcome to Guess My Number\n\n";
		srand(static_cast<unsigned int>(time(0)));
		int tries = 0;
		int choice, guess, diff;
		std::cout << "Do you want guess the number to computer? (y/n): ";
		std::cin >> command;
		std::cout << "1 - Easy(1-10)\n2 - Seriosly(1-100)\n3 - Crazy(1-400)\nAny different number - Unbeliveble(1-1000)\n";
		std::cout << "Enter difficult: ";
		std::cin >> choice;
		if (choice == 1) {
			diff = Difficult::Easy;
		}
		else if (choice == 2) {
			diff = Difficult::Seriosly;
		}
		else if (choice == 3) {
			diff = Difficult::Crazy;
		}
		else {
			std::cout << "Omg. You are a crazy!\n";
			diff = Difficult::Unbeliveble;
		}
		if (command == 'y') {
			std::cout << "Enter number to guess in diapazon from " << 1 << " to " << diff << ":";
			int secretUserNumber;
			std::cin >> secretUserNumber;
			int min = 0, max = diff + 1;
			do {
				guess = (max + min) / 2;
				++tries;
				if (guess > secretUserNumber) {
					std::cout << "Computer enter " << guess << " number. But it`s to high!\n";
					max = guess;
				}
				else if (guess < secretUserNumber) {
					std::cout << "Computer enter " << guess << " number. But it`s to low!\n";
					min = guess;
				}
				else if (tries > 1000) {
					std::cout << "Computer is to weak. You win for now!\n\n";
					break;
				}
				else {
					std::cout << "Computer enter " << guess << " number. And that`s right!\n";
					std::cout << "\nComputer got it in " << tries << " guesses! Congratilation computer, well done!\n";
				}
			} while (guess != secretUserNumber);
		}
		else {
			int secretNumber = rand() % diff + 1;
			std::cout << "Guesed number in diapazon from " << 1 << " to " << diff << "\n";
			do {
				std::cout << "Enter a guess: ";
				std::cin >> guess;
				++tries;
				if (guess > secretNumber) {
					std::cout << "Too high!\n\n";
				}
				else if (guess < secretNumber) {
					std::cout << "Too low!\n\n";
				}
				else {
					std::cout << "\nThat`s it! You got it in " << tries << " guesses!\n";
				}
			} while (guess != secretNumber);
		}
		std::cout << "Try again? (y/n)";
		std::cin >> command;
	}
	std::cout << "Okay, bye. See you later!\n";
	return 0;
}