#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <fstream>

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
	cout << "Enter what word you want to delete: ";
	cin >> word;
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
	cout << "Enter what word you want to add: ";
	cin >> word;cin.ignore(1);
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

int main() {
	string path = "data.txt";
	map <string, string> vocabular;
	ReadVocabular(path, vocabular);
	while (true) {
		string command;
		cout << "What you want to do" << endl;
		cout << "add - Add word to vocabulary" << endl;
		cout << "del - Delete word from vocabulary" << endl;
		cout << "shw - Show all words in vocabulary" << endl;
		cout << "ex - Exit from dictionary" << endl;
		cin >> command;
		if (command == "add") {
			AddWord(vocabular);
		}
		else if (command == "del") {
			DeleteWord(vocabular);
		}
		else if (command == "shw") {
			ShowAllWords(vocabular);
		}
		else if (command == "ex") {
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
