#include "profiler.h"
#include <algorithm>
#include <vector>
#include <future>
#include <numeric>

using namespace std;

template <typename T>
class SimpleVector {
public:
	explicit SimpleVector(int s, int assigmentNumb = 0) : size(s) {
		data = new T[s];
		capacity = size;
		end_ = data + size;
		for (int i = 0; i < size; ++i) {
			this->data[i] = assigmentNumb;
		}
	}
	SimpleVector(const SimpleVector<T>&& other)
		: data(other.data),
		size(other.size),
		capacity(other.capacity),
		end_(data+size)
	{
		other.data = nullptr;
		other.size = other.capacity = 0;
	}
	SimpleVector(const SimpleVector<T>& other)
		: data(new T[other.capacity]),
		size(other.size),
		capacity(other.capacity)
	{
		copy(other.begin(), other.end(), begin());
	}
	T& operator[](int index) {
		return data[index];
	}
	~SimpleVector() {
		delete[] data;
	}
	void operator=(SimpleVector&& other) {
		delete[] data;
		data = other.data;
		size = other.size;
		capacity = other.capacity;

		other.data = nullptr;
		other.size = other.capacity = 0;
	}
	int getSize() const;
	T* begin() {
		return data;
	}
	T* end() {
		return end_;
	}
	const T* begin() const {
		return data;
	}
	const T* end() const {
		return end_;
	}
	int getSize() {
		return size;
	}
private:
	T* data;
	int size;
	int capacity;
	T* end_;
};

int SumVectors(const SimpleVector<int>& one, const SimpleVector<int>& two) {
	future<int> f = async([&one] {
		return accumulate(begin(one), end(one), 0);
		});
	int result = accumulate(begin(two), end(two), 0);
	return result +f.get();
}

int main() {
	SimpleVector<int> first(10, 3), secomd(12, 1);
	cout << SumVectors(first, secomd);
	return 0;
}