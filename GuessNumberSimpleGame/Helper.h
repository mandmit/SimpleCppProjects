#pragma once
#include <iostream>

struct Helper {
	Helper() {
		holdedNumb = 0;
		floatedNumb = 0;
	}
	int holdedNumb;
	int floatedNumb;
	friend std::ostream& operator<< (std::ostream& out, Helper help) {
		out << "You guesed " << help.holdedNumb + help.floatedNumb << " numbs.\n"
			<< help.holdedNumb << " numbs on the position and " << help.floatedNumb
			<< " on the wrong position, but correct.\n";
		return out;
	}
};
