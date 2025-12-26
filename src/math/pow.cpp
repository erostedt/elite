/*
Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Constraints:

-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n is an integer.
Either x is not zero or n > 0.
-10^4 <= x^n <= 10^4
 */

#include "assert.hpp"
#include <iostream>

using namespace std;

class Solution
{
  public:
    double myPow(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (x == 0)
        {
            return 0;
        }
        if (x == 1)
        {
            return 1;
        }
        if (n < 0)
        {
            return myPow(1 / x, -n);
        }
        if ((n & 1) == 0)
        {
            return myPow(x * x, n / 2);
        }
        return x * myPow(x * x, n / 2);
    }

    double myPow(double x, int n)
    {
        return myPow(x, (long)n);
    }
};

int main()
{

    Solution solution;

    {
        const double x = 2.00000;
        const int n = 10;
        const double expected_output = 1024.00000;
        const double output = solution.myPow(x, n);

        Assert::close(output, expected_output);
    }

    {
        const double x = 2.10000;
        const int n = 3;
        const double expected_output = 9.26100;
        const double output = solution.myPow(x, n);

        Assert::close(output, expected_output);
    }

    {
        const double x = 2.00000;
        const int n = -2;
        const double expected_output = 0.25000;
        const double output = solution.myPow(x, n);

        Assert::close(output, expected_output);
    }

    cout << "All passed" << endl;
}
