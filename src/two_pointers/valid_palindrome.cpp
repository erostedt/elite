/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and
numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        erase_if(s, [](const char ch) -> bool { return !isalnum(ch); });
        transform(begin(s), end(s), begin(s), [](const char ch) -> char { return tolower(ch); });
        if (s.empty())
        {
            return true;
        }

        auto forward = cbegin(s);
        auto backward = prev(cend(s));
        while (forward < backward && *forward == *backward)
        {
            ++forward;
            --backward;
        }
        return *forward == *backward;
    }
};

int main()
{
    Solution solution;
    {
        const string s = "A man, a plan, a canal: Panama";

        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const string s = "race a car";

        const bool expected_output = false;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const string s = " ";

        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const string s =
            ".........................................................................................................."
            "......a..................................................................................................."
            ".........................................................................................................."
            "...................................";
        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
