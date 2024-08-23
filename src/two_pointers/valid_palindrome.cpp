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
        std::erase_if(s, [](const char ch) -> bool { return !std::isalnum(ch); });
        std::transform(std::begin(s), std::end(s), std::begin(s),
                       [](const char ch) -> char { return std::tolower(ch); });
        if (s.empty())
        {
            return true;
        }

        auto forward = std::cbegin(s);
        auto backward = std::prev(std::cend(s));
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
        const std::string s = "A man, a plan, a canal: Panama";

        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "race a car";

        const bool expected_output = false;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = " ";

        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s =
            ".........................................................................................................."
            "......a..................................................................................................."
            ".........................................................................................................."
            "...................................";
        const bool expected_output = true;
        const bool output = solution.isPalindrome(s);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
