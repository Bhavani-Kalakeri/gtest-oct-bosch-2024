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
  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_0_for_0){
  StringCalculator objUnderTest;
  string input = "0";
  int expValue = 0;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_a_single_number_returns_1_for_1){
  StringCalculator objUnderTest;
  string input = "1";
  int expValue = 1;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_2_comma_delimited_nums_return_their_sum){
  StringCalculator objUnderTest;
  string input = "17,13";
  int expValue = 30;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_multiple_comma_delimited_nums_return_their_sum){
  StringCalculator objUnderTest;
  string input = "3,13,1";
  int expValue = 17;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_delimited_with_newline_and_comma_return_their_sum){
  StringCalculator objUnderTest;
  string input = "3\n13,1";
  int expValue = 17;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_a_delimiter_return_their_sum_based_on_that_delimiter){
  StringCalculator objUnderTest;
  string input = "\n13;1//13";
  int expValue = 17;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_negative_nums_throws_an_exception_listing_invalid_values){
  StringCalculator objUnderTest;
  string input = "1, -3, 13, -7";
  
  //int expValue = 17;
  //int actValue = objUnderTest.Add(input);
  //ASSERT_EQ(expValue, actValue);

  //try{
    //objUnderTest.Add(input);
  //}
  //catch(

  ASSERT_THROW({
    objUnderTest.Add(input); 
    },std::invalid_argument);
  
}

TEST(string_calculator_add, when_passed_numbers_over_1000_ignore_them){
  StringCalculator objUnderTest;
  string input = "1, 1114, 13, 3";
  int expValue = 17;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_multichar_delimiter_use_that_delimiter_to_sum_values){
  StringCalculator objUnderTest;
  string input = "*[//]7[***]//[~~]1??2";
  int expValue = 10;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_multiple_delimiters_sums_on_each_delimiter){
  StringCalculator objUnderTest;
  string input = "[*]/[/]7[*]//~~1\n2";
  int expValue = 10;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}

TEST(string_calculator_add, when_passed_multiple_multichar_delimiters_sums_on_each_delimiter){
  StringCalculator objUnderTest;
  string input = "[~*]//7[*//~~]1\n2";
  int expValue = 10;

  int actValue = objUnderTest.Add(input);

  ASSERT_EQ(expValue, actValue);
}
