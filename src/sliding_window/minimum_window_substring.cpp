/*
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring,
return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    string minWindow(string s, string t)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        const std::string s = "ADOBECODEBANC";
        const std::string t = "ABC";

        const std::string expected_output = "BANC";
        const std::string output = solution.minWindow(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "a";
        const std::string t = "a";

        const std::string expected_output = "a";
        const std::string output = solution.minWindow(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "a";
        const std::string t = "aa";

        const std::string expected_output = "";
        const std::string output = solution.minWindow(s, t);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
