#include "CounterBot.h"

using std::cout;
using std::cin;

int main() {
	while (true) {
		std::string path = "";
		cout << "Enter path to file or word exit to terminate the program: ";
		cin >> path;
		if (path == "exit") {
			return 0;
		}
		try {
			CounterBot b(path);
			b.getInfo();
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << '\n';
		}
	}
	return 0;
}