#pragma once
#include <iostream>
#include <chrono>
#include <string>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::chrono::steady_clock;
using std::chrono::duration_cast;

#define UNIQ_ID_IMPL(lineno) _a_local_val_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define LOG_DURATION(message)	\
	LogDuration UNIQ_ID(__LINE__){message};

class LogDuration {
public:
	LogDuration(const string& mess = "") : message(mess + ": "), start(steady_clock::now()) {}
	~LogDuration();
private:
	string message;
	steady_clock::time_point start;
};