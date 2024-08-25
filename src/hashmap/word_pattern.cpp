/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool wordPattern(string pattern, string s)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        const std::string pattern = "abba";
        const std::string s = "dog cat cat dog";

        const bool expected_output = true;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string pattern = "abba";
        const std::string s = "dog cat cat fish";

        const bool expected_output = false;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }
    {
        const std::string pattern = "aaaa";
        const std::string s = "dog cat cat dog";

        const bool expected_output = false;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
