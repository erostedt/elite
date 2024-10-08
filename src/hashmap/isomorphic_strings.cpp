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
#include <unordered_map>
#include <unordered_set>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        if (std::size(s) != std::size(t))
        {
            return false;
        }

        std::unordered_map<char, char> s_to_t;
        std::unordered_map<char, char> t_to_s;
        for (size_t i = 0; i < std::size(s); ++i)
        {
            char x = s[i];
            char y = t[i];
            auto its = s_to_t.find(x);
            auto itt = t_to_s.find(y);
            if (its != std::end(s_to_t) && its->second != y)
            {
                return false;
            }
            if (itt != std::end(t_to_s) && itt->second != x)
            {
                return false;
            }
            s_to_t[x] = y;
            t_to_s[y] = x;
        }
        return true;
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
    {
        const std::string s = "badc";
        const std::string t = "baba";

        const bool expected_output = false;
        const bool output = solution.isIsomorphic(s, t);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
