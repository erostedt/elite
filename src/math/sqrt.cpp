/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer
should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.


Constraints:

0 <= x <= 2^31 - 1
 */

#include "assert.hpp"
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x < 0)
        {
            return -1;
        }

        unsigned long low = 0;
        unsigned long high = x;
        unsigned long target = x;
        while (low <= high)
        {
            unsigned long s = midpoint(low, high);
            if (s * s < target)
            {
                low = s + 1;
            }
            else if (s * s == target)
            {
                return s;
            }
            else
            {
                high = s - 1;
            }
        }
        return low - 1;
    }
};

int main()
{
    Solution solution;

    {
        const int x = 4;
        const int expected_output = 2;
        const int output = solution.mySqrt(x);

        Assert::equal(output, expected_output);
    }

    {
        const int x = 8;
        const int expected_output = 2;
        const int output = solution.mySqrt(x);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
