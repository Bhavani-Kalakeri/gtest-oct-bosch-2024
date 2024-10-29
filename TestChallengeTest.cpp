#include <gtest/gtest.h>
#include "TestChallenge.h"

using namespace std;

TEST(test_add_two_numbers,sum_of_two_numbers){
  int num1 = 10;
  int num2 = 7;
  int* result;
  int expValue = 17;
  
  Add(num1, num2, &result);
  
  ASSERT_EQ(expectedValue,result);
  }
