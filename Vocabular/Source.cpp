#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

void ReadVocabular(const string& path, map <string, string>& emptyVocabular) {
	ifstream file(path);
	if (!file.is_open()) {
		ofstream file("data.txt");
		cout << "File created" << endl;
	}
	else {
		string meaning,word;
		if (file.peek() != '\n') {
			while (!file.eof()) {
				getline(file, word, '\t');
				getline(file, meaning);
				emptyVocabular[word] = meaning;
			}
		}
	}
	file.close();
}

void DeleteWord(map<string, string>& vocabulary) {
	string word;
	cout << "Enter what word or phrase you want to delete: ";
	cin.ignore();
	getline(cin, word);
	if (vocabulary.count(word) == 1) {
		vocabulary.erase(word);
		cout << "Word successfully deleted from your vocabulary!" << endl;
	}
	else {
		cout << "Word is missing in vocabulary." << endl;
	}
}

void AddWord(map<string, string>& vocabulary) {
	string word;
	cout << "Enter what word you want to add (or few words): ";
	cin.ignore();
	getline(cin, word);
	if (vocabulary.count(word) == 1) {
		cout << "Word already exist in your vocabulary!" << endl;
	}
	else {
		string meaning;
		cout << "Now enter meaning or examples of this word: ";
		getline(cin, meaning);
		vocabulary[word] = meaning;
		cout << "Word successfully added to vocabulary." << endl;
	}
}

void ShowAllWords(const map<string, string>& vocabulary) {
	cout << "<---------------------------------------------------------->" << endl;
	if (vocabulary.size() != 0) {
		for (const auto& c : vocabulary) {
			cout << c.first << "\t" << c.second << endl;
		}
	}
	else {
		cout << "Nothing to show" << endl;
	}
	cout << "<---------------------------------------------------------->" << endl;
}

void RewriteVocabular(const string& path, const map <string, string>& vocabular) {
	ofstream file(path);
	int cnt = 0;
	for (const auto& c : vocabular) {
		if (cnt != vocabular.size()-1) {
			file << c.first << '\t' << c.second << endl;
		}
		else {
			file << c.first << '\t' << c.second;
		}
		cnt++;
	}
	file.close();
	cout << "File is successfully modified";
}

void StartBlitz(const map<string, string>& vocabular, const vector<string>& keys, int& score) {
	system("cls");
	cout << "Blitz has started!";
	for (int i = 0; i < keys.size(); ++i) {
		string word = keys[i];
		cout << "Enter the meaning of: \t" << word << "\t - > ";
		string guess;
		cin.ignore();
		getline(cin, guess);
		if (guess == vocabular.at(word)) {
			++score;
		}
		else {
			return;
		}
	}
}

void ChangeMeaning(map<string, string>& vocabulary, const string& word) {
	if (vocabulary.count(word) == 1) {
		cout << "Word was finded.\Previous meaning of this word (phrase): " << vocabulary.at(word) << "\nNew meaning is: ";
		cin.ignore();
		getline(cin, vocabulary[word]);
	}
	else {
		cout << "Word was not finded.";
	}
}

int main() {
	string path = "data.txt";
	map <string, string> vocabular;
	ReadVocabular(path, vocabular);
	while (true) {
		char command;
		cout << "What you want to do" << endl;
		cout << "a - Add word to vocabulary\nd - Delete word from vocabulary\ns - Show all words in vocabulary\nb - Start blitz\ne - Exit from dictionary" << endl;
		cin >> command;
		if (command == 'a') {
			AddWord(vocabular);
		}
		else if (command == 'd') {
			DeleteWord(vocabular);
		}
		else if (command == 's') {
			ShowAllWords(vocabular);
		}
		else if (command == 'b') {
			int score = 0;
			vector<string> keys;
			keys.reserve(vocabular.size());
			for (const auto& el : vocabular) {
				keys.push_back(el.first);
			}
			std::random_device rd;
			std::mt19937 g(rd());
			shuffle(keys.begin(), keys.end(), g);
			StartBlitz(vocabular, keys, score);
			cout << "You scored " << score << " out of " << keys.size() << endl;
		}
		else if (command == 'e') {
			RewriteVocabular(path, vocabular);
			break;
		}
		else {
			cout << "You entered wrong command!" << endl;
			cout << "Please try again." << endl;
		}
	}
	return 0;
}
