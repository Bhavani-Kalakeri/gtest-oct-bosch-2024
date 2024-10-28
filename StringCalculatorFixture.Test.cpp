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


