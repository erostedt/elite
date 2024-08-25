/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two
characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        const std::string s = "egg";
        const std::string t = "add";

        const bool expected_output = true;
        const bool output = solution.isIsomorphic(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "foo";
        const std::string t = "bar";

        const bool expected_output = false;
        const bool output = solution.isIsomorphic(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "paper";
        const std::string t = "title";

        const bool expected_output = true;
        const bool output = solution.isIsomorphic(s, t);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
