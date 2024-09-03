/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not
include 1. Those numbers for which this process ends in 1 are happy. Return true if n is a happy number, and false if
not.



Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false


Constraints:

1 <= n <= 231 - 1
*/

#include <iostream>
#include <unordered_set>

#include "assert.hpp"

int sum_of_squared_digits(int n)
{
    int sum = 0;
    int digit;
    while (n > 0)
    {
        digit = n % 10;
        sum += digit * digit;
        n = n / 10;
    }
    return sum;
}

using namespace std;
class Solution
{
  public:
    bool isHappy(int n)
    {
        if (n < 1)
        {
            return false;
        }

        std::unordered_set<int> seen;
        while (n != 1)
        {
            if (seen.contains(n))
            {
                return false;
            }

            seen.insert(n);
            n = sum_of_squared_digits(n);
        }

        return true;
    }
};

int main()
{
    Solution solution;
    {
        const int n = 19;

        const bool expected_output = true;
        const bool output = solution.isHappy(n);

        Assert::equal(output, expected_output);
    }
    {
        const int n = 2;

        const bool expected_output = false;
        const bool output = solution.isHappy(n);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
