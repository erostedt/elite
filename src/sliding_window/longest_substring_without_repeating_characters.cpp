/*
Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        const std::string s = "abcabcbb";

        const int expected_output = 3;
        const int output = solution.lengthOfLongestSubstring(s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "bbbbb";

        const int expected_output = 1;
        const int output = solution.lengthOfLongestSubstring(s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "pwwkew";

        const int expected_output = 3;
        const int output = solution.lengthOfLongestSubstring(s);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
