#include "StringCalculator.h"
#include <gtest/gtest.h>

Class StringCalculatorAddFixture:public testing::Test
  protected:
    StringCalculator *objUnderTest;
  void Setup() override{
    objUnderTest = new StringCalculator;
  }
void TearDown() override{
   delete objUnderTest;
}
};

TEST_F(StringCalculatorAddFixture, Returns_0_For_Empty){
    string input="";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorAddFixture, Returns_0_For_0){
    string input="0";
    int expectedValue=0;
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}

TEST_F(StringCalculatorAddFixture, Return_1_For_1){
    string input = "1";
    int expValue = 1;
    int actValue = objUnderTest->Add(input);

    ASSERT_EQ(actVal, expValue);
}

TEST_F(StringCalculatorAddFixture, Return_Sum_For_2_Nums_With_Comma_Delimiter){
    string input = "13,7";
    int expValue = 20;
    int actValue = objUnderTest->Add(input);

    ASSERT_EQ(actVal, expValue);
}
