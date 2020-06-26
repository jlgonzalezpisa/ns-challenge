/**
 * @file LargestSumFinder.h
 *
 * @brief Declaration of useful functions for solution of second problem.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 * @revision 1
 *
 * PROBLEM STATEMENT
 * Given an integer (T) and a collection of integer (I), find a sub-collection (M) that the sum (S)
 * of M's elements is the largest among all sub-collections of I and S <= T. I is not sorted, M is not
 * required to be sorted. Not required to find M with the least number of elements. I and M might
 * contain repetitive elements. If there’s no answer found set M to an empty vector and s to 0.
 *
 * Signature of the interface :
 * void find_largest_sum(const uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S);
 */

#ifndef CHALLENGE_LARGESTSUMFINDER_H
#define CHALLENGE_LARGESTSUMFINDER_H

/* INCLUDES ******************************************************************/
#include <cstdint>
#include <vector>

/* CLASS DECLARATION *********************************************************/
namespace challenge
{

/**
 * @brief Find the largest sum (following the problem constraints) of a given set of numbers.
 */
class LargestSumFinder
{
public:
  /**
   * @brief Find the largest sum <= T of sub sets of a given set of numbers.
   *
   * @param T The maximum value of the sum of subsets.
   * @param I The set of numbers.
   * @param M (Output) A subset whose values sum S
   * @param S (Output) The largest sum <= T of subset elements
   */
  static void find_largest_sum(const uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S);

private:
  /**
   * @brief Implementation of the recursive knapSack solution using dynamic programing.
   * (In this case, the weights and values are the same)
   *
   * @param W Represents the capacity in the knapSack problem.
   * @param values The set weights (=values) in the knapSack problem.
   * @param n number of items of 'values' to be considered.
   * @param M (Output) A subset whose values sum the largest possible.
   *
   * @return The largest sum found in subsets.
   */
  static uint32_t knapSack(int W, const std::vector<uint32_t>& values, int n, std::vector<uint32_t>& M);
};

}

#endif //CHALLENGE_LARGESTSUMFINDER_H
