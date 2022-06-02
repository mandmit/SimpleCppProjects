#include <iostream>
#include "GameBot.h"

using std::cout; using std::cin;

int main() {
	srand(time(0));
	int again = 1;
	while (again) {
		int diff = 2;
		cout << "Choose your complexity(how many numbs you wanna guess)? ";
		cin >> diff;
		GameBot guru(diff);
		std::string s = "null";
		std::string expect;
		guru.getGuess(expect);
		do {
			if (s != "null") {
				cout << guru.help(s);
			}
			cout << "Your guess: ";
			cin >> s;
		} while (!guru.isCorrect(s));
		cout << "Congrats!!! You guesed the word. Do you wanna play again?\nAny numb - yes\t0 - exit\n";
		cin >> again;
	}
	return 0;
}