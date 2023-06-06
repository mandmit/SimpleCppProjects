#include "pch.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vect) {
	os << '[';
	for (int i = 0; i < vect.size(); ++i) {
		if (i) {
			os << ',';
		}
		os << vect[i];
	}
	os << ']' << '\n';
	return os;
}

//using namespace std;
//
//void doSomeStuff(atomic<int>* a_int) {
//	printf("Id of current thread: %d\n", this_thread::get_id());
//	for (int i = 0; i < 10; ++i) {
//		{
//			(*a_int) += i;
//		}
//		printf("Current thread id: %d with iteration: %d and Value: %d\n", this_thread::get_id(), i, (*a_int).load());
//		this_thread::sleep_for(20ms);
//	}
//}
//
//class Base {
//public:
//	virtual void SayHello() {
//		cout << "Hello(Base) text from " << typeid(*this).name() << endl;
//	}
//private:
//	int getValue() {
//		int numb = 9;
//		return numb;
//	}
//};
//
//class Derrived : public Base {
//public:
//	void SayHello() override {
//		cout << "Hi(Derrived) from " << typeid(*this).name() << endl;
//	}
//	//First case: create function that can call Base version itself
//	void SayHelloFromParent() {
//		Base::SayHello();
//	}
//};
//
//class Derrived2 : public Base {
//public:
//	void SayHello() override {
//		cout << "Tsap(Derrived) from " << typeid(*this).name() << endl;
//	}
//};
//
//typedef std::pair<std::type_index, std::type_index> MyCustomPair;
//typedef std::unordered_set<MyCustomPair> MyCustomSet;
//
//namespace std {
//	template <> struct hash<MyCustomPair> {
//		size_t operator()(const MyCustomPair& p) const {
//			hash<string> h;
//			return h(p.first.name()) ^ h(p.second.name());
//		}
//	};
//}
//
//
//ostream& operator<<(ostream& os, MyCustomPair p) {
//	os << p.first.name() << ' ' << p.second.name() << endl;
//	return os;
//}
//
//int main() {
//	//atomic_int* a_int = new atomic_int(0);//same as atomic<int> a_int = 0;
//	//thread workerThread(doSomeStuff, a_int);
//	//thread workerThread2(doSomeStuff, a_int);
//	//vector<thread*> threadsArr;
//	//threadsArr.push_back(&workerThread);
//	//threadsArr.push_back(&workerThread2);
//	//for (auto* thr : threadsArr) {
//	//	thr->join();
//	//}
//	std::function<int(int, int)> func = [](int a, int b) { return a + b; };
//	Base* b1 = new Derrived();
//	Base* b2 = new Derrived2();
//	std::pair<std::type_index, std::type_index> p{ typeid(*b1), typeid(*b2) };
//	(*b1).SayHello();
//	//First case
//	Derrived* der = dynamic_cast<Derrived*>(b1);
//	der->SayHelloFromParent();
//	//Second case: cast to base type and call function
//	((Base)(*b1)).SayHello();
//	//Third case: call Base version of function explicitly if public
//	b1->Base::SayHello();
//	MyCustomSet s;
//	s.insert(p);
//	cout << (*s.begin()) << endl;
//	delete b1;
//	delete b2;
//	return 0;
//}

using namespace std;

//template <int ... T>
//struct IntList;
//
//template <int H, int ...T>
//struct IntList<H, T...>
//{
//	static int const Head = H;
//	using Tail = IntList<T...>;
//};
//
//template <>
//struct IntList<> {};
//
//
//template <typename IL>
//struct Length
//{
//	static int const value = 1 + Length<typename IL::Tail>::value;
//};
//
//template <>
//struct Length<IntList<>>
//{
//	static int const value = 0;
//};
//
//
//template <int N, typename IL>
//struct IntCons;
//
//
//template <int N, typename ...List>
//struct IntCons
//{
//	using type = IntList<N, List...>;
//};
//
//// реализация метафункции Generate
//template <int N, typename IL>
//struct Generate;
//
//template <int N, typename ...List>
//struct Generate
//{
//	using type = IntCons<N, IntCons<N - 1, List...>>;
//};
//
//template <>
//struct Generate<0>
//{
//	using type = IntList<>;
//};

int main() {
	//using L1 = IntList<2, 3, 4>;
	using namespace string_literals;


	//using L2 = IntCons<1, L1>::type;   // IntList<1,2,3,4>

	//using L3 = Generate<5>::type;      // IntList<0,1,2,3,4>
	return 0;
}