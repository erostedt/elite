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
#include <unordered_map>

#include "assert.hpp"

using namespace std;

unordered_map<char, size_t> get_char_counts(const string &str)
{
    unordered_map<char, size_t> counts;
    for (const char ch : str)
    {
        counts[ch] += 1;
    }
    return counts;
}

class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        auto char_counts = get_char_counts(magazine);
        for (const char ch : ransomNote)
        {
            auto it = char_counts.find(ch);
            if (it == end(char_counts))
            {
                return false;
            }

            auto count = it->second;
            --count;
            if (count == 0)
            {
                char_counts.erase(ch);
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    {
        const string ransomNote = "a";
        const string magazine = "b";

        const bool expected_output = false;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }
    {
        const string ransomNote = "aa";
        const string magazine = "ab";

        const bool expected_output = false;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }
    {
        const string ransomNote = "aa";
        const string magazine = "aab";

        const bool expected_output = true;
        const bool output = solution.canConstruct(ransomNote, magazine);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
