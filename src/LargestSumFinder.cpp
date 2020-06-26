/**
 * @file LargestSumFinder.cpp
 *
 * @brief Implementation of LargestSumFinder class.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 * @revision 1
 */

/* INCLUDES ******************************************************************/
#include "LargestSumFinder.h"
#include <algorithm>

/* LOCAL VARIABLES ******************************************************/
std::vector < std::vector <uint32_t> > maximums;
const int NOT_VISITED = -1;

/* CLASS IMPLEMENTATION ******************************************************/
namespace challenge
{

void LargestSumFinder::find_largest_sum
(const uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S)
{
  // Maximums contains the table (n x T +1) to  allow Dynamic Programing
  maximums = std::vector < std::vector <uint32_t> > (I.size(), std::vector <uint32_t>(T + 1, NOT_VISITED) );
  M = std::vector<uint32_t>();

  // Knapsack algorithm is invoked using W = T for the last element of I
  S = knapSack(T, I, I.size() - 1, M);
}

uint32_t LargestSumFinder::knapSack(int W, const std::vector<uint32_t>& values, int n, std::vector<uint32_t>& M)
{
  if (n < 0)
    return 0;

  // If the value does exist in the table, it is returned
  if(maximums[n][W] != NOT_VISITED)
    return maximums[n][W];

  // If the element is bigger than W, it is not included and returns the knapSack value for the next element (n-1)
  if (values[n] > W)
  {
    maximums[n][W] = knapSack(W, values, n-1, M);
    return maximums[n][W];
  }

  else
  {
    std::vector<uint32_t> including(M);
    std::vector<uint32_t> excluding(M);

    // We add the current element to be returned in case it has the maximum value
    including.push_back(values[n]);

    // The sum when the current element is included
    uint32_t include = values[n] + knapSack(W - values[n], values, n - 1, including);

    // The sum when the current element is not included
    uint32_t exclude = knapSack(W, values, n - 1, excluding);

    maximums[n][W] = std::max(include, exclude);

    if(include == maximums[n][W])
      M = including;
    else
      M = excluding;

    return maximums[n][W];
  }
}

}
