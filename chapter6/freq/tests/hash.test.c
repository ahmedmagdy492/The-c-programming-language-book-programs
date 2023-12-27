#include <unity/unity.h>
#include "../hashtable.h"

void setUp() {

}

void test_calchashForCorrectOutput() {
  int actual = calchash("ahmed");
  int expected = 11;
  printf("actual = %d, expected = %d\n", actual, expected);
  TEST_ASSERT_TRUE(actual == expected);
}

void tearDown() {

}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_calchashForCorrectOutput);
  
  UNITY_END();
}
