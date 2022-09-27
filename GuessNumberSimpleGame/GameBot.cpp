#include "GameBot.h"

GameBot::GameBot(int n) {
	std::cout << "Your complexity is " << n << " numbs\n";
	this->generated = Generator(n);
	this->controleSum = Summurize(this->generated);
}

GameBot::GameBot(const std::string& word)
{
	this->generated = word;
	this->controleSum = Summurize(this->generated);
}

GameBot::GameBot() : GameBot::GameBot(3) {}

std::string GameBot::Generator(int n) {
	std::string s;
	for (int i = 0; i < n; i++) {
		s += std::to_string((rand()) % 10);
	}
	return s;
}

void GameBot::getGuess(std::string& guess) {
	guess.clear();
	guess.append(this->generated);
}

std::map<char, int> GameBot::Summurize(const std::string& word) const
{
	std::map<char, int> m;
	for (auto c : word) {
		m[c]++;
	}
	return m;
}

bool GameBot::isCorrect(const std::string& word) const {
	return word == this->generated;
}

Helper GameBot::help(const std::string& word) const {
	Helper helper;
	std::map<char, int> testWord = Summurize(word);
	std::map<char, int> temp = this->controleSum;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == this->generated[i]) {
			testWord[word[i]]--;
			temp[word[i]]--;
			helper.holdedNumb++;
			if (temp[word[i]] == 0) {
				temp.erase(word[i]);
			}
		}
	}
	for (const auto& [k, v] : temp) {
		if (testWord.count(k) == 1) {
			if (v == testWord[k] || v < testWord[k]) {
				helper.floatedNumb += v;
			}
			else {
				helper.floatedNumb += testWord[k];
			}
		}
	}
	return helper;
}