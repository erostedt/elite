/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this
range, inclusive.

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0


Constraints:

0 <= left <= right <= 2^31 - 1
 */

#include "assert.hpp"
#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shifts = 0;
        while (left != right && left > 0)
        {
            left >>= 1;
            right >>= 1;
            ++shifts;
        }

        return left << shifts;
    }
};

int main()
{

    Solution solution;

    {
        const int left = 5;
        const int right = 7;
        const int expected_output = 4;
        const int output = solution.rangeBitwiseAnd(left, right);

        Assert::equal(output, expected_output);
    }

    {
        const int left = 0;
        const int right = 0;
        const int expected_output = 0;
        const int output = solution.rangeBitwiseAnd(left, right);

        Assert::equal(output, expected_output);
    }

    {
        const int left = 1;
        const int right = 2147483647;
        const int expected_output = 0;
        const int output = solution.rangeBitwiseAnd(left, right);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
