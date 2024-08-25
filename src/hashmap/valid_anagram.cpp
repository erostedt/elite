/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the
original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include <iostream>
#include <string>
#include <unordered_map>

#include "assert.hpp"

using namespace std;
using CharCountMap = std::unordered_map<char, size_t>;

CharCountMap char_counts(const std::string &str)
{
    std::unordered_map<char, size_t> count;
    for (const char ch : str)
    {
        count[ch] += 1;
    }
    return count;
}

bool hashmap_equals(const CharCountMap &map1, const CharCountMap &map2)
{
    const auto map1_end = std::cend(map1);
    const auto map2_end = std::cend(map2);
    for (const auto &[ch, count] : map1)
    {
        const auto &value = map2.find(ch);
        if (value == map2_end || value->second != count)
        {
            return false;
        }
    }
    for (const auto &[ch, count] : map2)
    {
        const auto &value = map1.find(ch);
        if (value == map1_end || value->second != count)
        {
            return false;
        }
    }
    return true;
}

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        return (std::size(s) != std::size(t)) ? false : hashmap_equals(char_counts(s), char_counts(t));
    }
};

int main()
{
    Solution solution;
    {
        const std::string s = "anagram";
        const std::string t = "nagaram";

        const bool expected_output = true;
        const bool output = solution.isAnagram(s, t);

        Assert::equal(output, expected_output);
    }
    {
        const std::string s = "rat";
        const std::string t = "car";

        const bool expected_output = false;
        const bool output = solution.isAnagram(s, t);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
