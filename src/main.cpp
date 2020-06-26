/**
 * @file main.cpp
 *
 * @brief Invocation and testing of two challenge problems for avantica process.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 *
 */

/* INCLUDES ******************************************************************/
#include <Adder.h>
#include <AddOverflowException.h>
#include <LargestSumFinder.h>

#include <iostream>

/* PROTOTYPES ******************************************************************/
int add(int a, int b);
void find_largest_sum(const uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S);

bool testFirstProblem();
bool testSecondProblem();


/* MAIN ******************************************************************/
int main()
{
  testFirstProblem();
  testSecondProblem();

  return 0;
}

/* IMPLEMENTATIONS ******************************************************************/

int add(int a, int b)
{
  return challenge::Adder::add(a, b);
}

void find_largest_sum(const uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S)
{
  challenge::LargestSumFinder::find_largest_sum(T, I, M, S);
}

/* TESTS ******************************************************************/
bool testFirstProblem()
{
  std::cout << "FIRST PROBLEM RESULTS" << std::endl;
  std::cout << "=====================" << std::endl;

  int scenarios [][2]= {
    // Positives
    {1, 1}, // 0
    {1, 2}, // 1
    {1000, 2000}, // 2
    {2000, 1000}, // 3
    {0, 0}, // 4

    // Negatives
    {-1, -1}, // 5
    {-1, -2}, // 6
    {-1000, -2000}, // 7
    {-2000, -1000}, // 8

    // Limit
    {INT_MAX - 1, 1}, // 9
    {INT_MIN + 1, -1}, // 10

    // Launch exception
    {INT_MAX, 1}, // 11
    {INT_MIN, -1} // 12
  };

  for (int i=0; i<=10; i++)
  {
    int result = add(scenarios[i][0], scenarios[i][1]);
    std::cout << "Scenario " << i + 1  << " : (";
    std::cout << scenarios[i][0] << ") + ("<< scenarios[i][1] << ") = " << result << std::endl;
  }

  // First exception
  try
  {
    int result = add(scenarios[11][0], scenarios[11][1]);
  }
  catch (AddOverflowException &e)
  {
    std::cout << "AddOverflowException caught: ";
    std::cout << e.what() << std::endl;
  }

  // Second exception
  try
  {
    int result = add(scenarios[12][0], scenarios[12][1]);
  }
  catch (AddOverflowException &e)
  {
    std::cout << "AddOverflowException caught: ";
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl << std::endl;

  return true;
}

bool testSecondProblem()
{
  std::cout << "SECOND PROBLEM RESULTS" << std::endl;
  std::cout << "=====================" << std::endl;

  std::vector<uint32_t> scenario1 = std::vector<uint32_t>({1,2,3,4,5,6,7});
  std::vector<uint32_t> scenario2 = std::vector<uint32_t>({});
  std::vector<uint32_t> scenario3 = std::vector<uint32_t>(10000, 2);

  std::vector<uint32_t> M;

  uint32_t T = 11;
  uint32_t S;

  // First scenario
  std::cout << "FIRST SCENARIO" << std::endl;

  find_largest_sum(T, scenario1, M, S);
  std::cout << "Largest value: " << S << std::endl;

  std::cout << "Sub-collection: { ";
  for(int i = 0; i < M.size(); i++)
    std::cout << M[i] << "  ";
  M.clear();

  std::cout << "}" << std::endl;

  // Second scenario
  std::cout << "SECOND SCENARIO" << std::endl;

  find_largest_sum(T, scenario2, M, S);
  std::cout << "Largest value: " << S << std::endl;

  std::cout << "Sub-collection: { ";
  for(int i = 0; i < M.size(); i++)
    std::cout << M[i] << "  ";
  M.clear();

  std::cout << "}" << std::endl;

  // Third scenario
  find_largest_sum(T, scenario3, M, S);
  std::cout << "Largest value: " << S << std::endl;

  std::cout << "Sub-collection: { ";
  for(int i = 0; i < M.size(); i++)
    std::cout << M[i] << "  ";

  std::cout << "}" << std::endl;

  return true;
}