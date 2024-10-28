#include "StringCalculator.h"
#include <gtest/gtest.h>

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_Empty){
  //Arrange
  StringCalculator objUnderTest;
  string input = "";
  int expValue = 0;

  //Act
  int actValue = objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expValue, ActValue);

