/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the
characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.


Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to
see if t has its subsequence. In this scenario, how would you change your code?
*/

#include <iostream>
#include <string>
#include <string_view>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        auto current_char = std::cbegin(s);
        auto last_char = std::cend(s);

        std::string_view remaining_text(t);
        while (current_char < last_char)
        {
            size_t match = remaining_text.find(*current_char);
            if (match == std::string_view::npos)
            {
                return false;
            }
            ++current_char;
            remaining_text = remaining_text.substr(match + 1);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    {
        const std::string s = "abc";
        const std::string t = "ahbgdc";

        const bool expected_output = true;
        const bool output = solution.isSubsequence(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "axc";
        const std::string t = "ahbgdc";

        const bool expected_output = false;
        const bool output = solution.isSubsequence(s, t);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
