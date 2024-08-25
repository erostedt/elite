/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from
magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

#include <iostream>
#include <string>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        const std::string ransomNote = "a";
        const std::string magazine = "b";

        const bool expected_output = false;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }
    {
        const std::string ransomNote = "aa";
        const std::string magazine = "ab";

        const bool expected_output = false;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }
    {
        const std::string ransomNote = "aa";
        const std::string magazine = "aab";

        const bool expected_output = true;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
