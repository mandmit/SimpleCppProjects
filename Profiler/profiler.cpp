#include <string>
#include "profiler.h"

LogDuration::~LogDuration() {
	auto finish = steady_clock::now();
	auto duration = finish - start;
	cerr << message << duration_cast<std::chrono::milliseconds>(duration).count() << " ms" << endl;
};