/*
 Given an integer x, return true if x is a palindrome, and false otherwise.


Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-2^31 <= x <= 2^31 - 1
*/

#include "assert.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        const auto str = to_string(x);
        const auto mid = begin(str) + (end(str) - begin(str)) / 2;
        return equal(begin(str), mid, rbegin(str));
    }
};

int main()
{
    Solution solution;

    {
        const int x = 121;

        const bool expected_output = true;
        const bool output = solution.isPalindrome(x);

        Assert::equal(output, expected_output);
    }

    {
        const int x = -121;

        const bool expected_output = false;
        const bool output = solution.isPalindrome(x);

        Assert::equal(output, expected_output);
    }

    {
        const int x = 10;

        const bool expected_output = false;
        const bool output = solution.isPalindrome(x);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
