/**
 * @file Adder.cpp
 *
 * @brief Implementation of Adder class.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 * @revision 1
 */

/* INCLUDES ******************************************************************/
#include "Adder.h"
#include <AddOverflowException.h>

/* CLASS IMPLEMENTATION ******************************************************/
namespace challenge
{

int Adder::add(int a, int b)
{
  int carry;
  // Return variable is used to calculate, "a" value is kept to compare signs at the end (to check overflow)
  int ret = a;
  // Overflow in result is checked only when variables have different sign
  bool checkOverflow = haveSameSign(a, b);

  while (b != 0)
  {
    carry = ret & b;
    ret = ret ^ b;
    b = carry << 1;
  }

  // If both params have the same sign, the result would have the same sign
  if (checkOverflow && !haveSameSign(ret, a))
    throw AddOverflowException();

  return ret;
}

bool Adder::haveSameSign(int a, int b)
{
  // xor operation is used to check signs
  return (a >= 0) ^ (b < 0);
}


}