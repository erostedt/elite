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
#include <unordered_map>

#include "assert.hpp"

using namespace std;
class Solution
{
    vector<string> split_by_space(const string &s)
    {
        istringstream iss(s);
        vector<string> result;
        string word;

        while (iss >> word)
        {
            result.push_back(word);
        }
        return result;
    }

  public:
    bool wordPattern(string pattern, string s)
    {
        const auto words = split_by_space(s);
        if (pattern.size() != words.size())
        {
            return false;
        }

        unordered_map<char, string> ch_to_str{};
        for (size_t i = 0; i < pattern.size(); ++i)
        {
            auto [it, inserted] = ch_to_str.try_emplace(pattern[i], words[i]);
            if (!inserted && it->second != words[i])
            {
                return false;
            }
        }

        unordered_map<string, char> str_to_ch{};
        for (size_t i = 0; i < pattern.size(); ++i)
        {
            auto [it, inserted] = str_to_ch.try_emplace(words[i], pattern[i]);
            if (!inserted && it->second != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    {
        const string pattern = "abba";
        const string s = "dog cat cat dog";

        const bool expected_output = true;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }
    {
        const string pattern = "abba";
        const string s = "dog cat cat fish";

        const bool expected_output = false;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }
    {
        const string pattern = "aaaa";
        const string s = "dog cat cat dog";

        const bool expected_output = false;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }
    {
        const string pattern = "abba";
        const string s = "dog dog dog dog";

        const bool expected_output = false;
        const bool output = solution.wordPattern(pattern, s);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
