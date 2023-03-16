#include "pch.h"
#include "../DiceRoller/DiceRoller/DiceRoller.cpp"

TEST(TestDiceRoller, Case_1) {
	DiceRoller dice("2d1+2");
  ASSERT_EQ(dice.getResult(), 4);
  std::cout << "As expected!\n";
}

TEST(TestDiceRoller, Case_2) {
	DiceRoller dice("2d1-2");
  ASSERT_EQ(dice.getResult(), 0);
  std::cout << "As expected!\n";
}

TEST(TestDiceRoller, Case_3) {
	DiceRoller dice("2d1");
  ASSERT_EQ(dice.getResult(), 2);
  std::cout << "As expected!\n";
}

TEST(TestDiceRoller, Case_4) {
	DiceRoller dice("d1+2");
  ASSERT_EQ(dice.getResult(), 3);
  std::cout << "As expected!\n";
}

template <typename T>
bool is_Negative(const T& val) {
	return val < 0;
}

TEST(TestFuncIsNegative, Case_1) {
	ASSERT_EQ(is_Negative(-8.4), true);
	std::cout << "As expected!\n";
}

TEST(TestFuncIsNegative, Case_2) {
	ASSERT_EQ(is_Negative(8), false);
	std::cout << "As expected!\n";
}

TEST(TestFuncIsNegative, Case_3) {
	ASSERT_EQ(is_Negative(-6.2), true);
	std::cout << "As expected!\n";
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}