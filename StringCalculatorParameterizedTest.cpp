#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>

using namespace std;

//fixture class
class StringCalculatorAddFixture : public testing::Test{
  protected:
    StringCalculator *objUnderTest;
    void SetUp() override{
      objUnderTest = new StringCalculator();
    }
    void TearDown() override{
      delete objUnderTest;
    }
};

//parameterized fixture
class StringCalculatorAddParameterizedFixture : public StringCalculatorAddFixture,
                                                public testing::WithParamInterface<tuple<string,int>>{
};

//For Valid Values Sum
INSTANTIATE_TEST_SUITE_P(ValidValueSet, StringCalculatorAddParameterizedFixture, testing::Values(
make_tuple("",0), make_tuple("0",0), make_tuple("1",1),  //single values sum
make_tuple("1,2",3), //two num sum
make_tuple("3,13,1",17), 
make_tuple("3\n13\n1\n",17),  //new line delimiter
make_tuple("*%1,\n13//",14)));  //multiple delimiters

//parameterized test
TEST_P(StringCalculatorAddParameterizedFixture, DataDrivenTestCase){
    string input=std::get<0>(GetParam());
    int expValue=std::get<1>(GetParam());
   
    int actValue=objUnderTest->Add(input);
    
    ASSERT_EQ(actValue,expValue);
}

//negetive case test
TEST_F(StringCalculatorAddFixture, Throw_Invalid_Argument_For_Neg_Number){
    string input="-3,1,14";
    EXPECT_THROW(objUnderTest->Add(input),invalid_argument);
  }
