#include <iostream>
#include <string>

int main() {
	int m = 0;
	while (!m) {
		std::cout << "Minutes: ";
		std::cin >> m;
	}
	m *= 60;
	std::string command("shutdown /s /t " + std::to_string(m));
	const char* arr = command.c_str();
	std::cout << arr;
	system(arr);
	return 0;
}