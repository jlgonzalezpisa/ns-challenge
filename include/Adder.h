/**
 * @file Adder.h
 *
 * @brief Declaration of useful functions for solution of first problem.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 * @revision 1
 *
 * PROBLEM STATEMENT
 * Use bit operator(s) to calculate the sum of two integers, check overflow with bit operator too.
 * Throw an exception in case of overflow. Comparison operators are allowed.
 *
 * Signature of the interface : int add(int a, int b);
 */

#ifndef CHALLENGE_ADDER_H
#define CHALLENGE_ADDER_H

/* INCLUDES ******************************************************************/
#include <exception>
#include <string>

/* CLASS DECLARATION *********************************************************/
namespace challenge
{

/**
 * @brief Use of bit operators to calculate sum of integers.
 */
class Adder
{
public:
  /**
  * @brief Sums the two parameters using bit operators.
  *
  * @param a The first integer.
  * @param b The second integer.
  *
  * @return The sum of a + b.
  * @throw AddOverflowException if overflow exists in the result.
  */
  static int add(int a, int b);

private:
  /**
  * @brief Establish if the two parameters have the same sign.
  *
  * @param a A signed integer.
  * @param b Another signed integer.
  *
  * @return False if one parameter is negative and the other is positive.
  */
  static bool haveSameSign(int a, int b);
};

}




#endif //CHALLENGE_ADDER_H
