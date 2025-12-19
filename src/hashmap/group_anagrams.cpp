/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the
original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    string sorted(string s)
    {
        sort(begin(s), end(s));
        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagrams{};
        for (const auto &s : strs)
        {
            anagrams[sorted(s)].push_back(s);
        }

        vector<vector<string>> out;
        out.reserve(anagrams.size());
        for (auto &&s : anagrams)
        {
            out.push_back(s.second);
        }
        return out;
    }
};

int main()
{
    using Matrix = std::vector<std::vector<std::string>>;
    Solution solution;
    {
        std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

        const Matrix expected_output = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
        const Matrix output = solution.groupAnagrams(strs);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector<std::string> strs = {""};

        const Matrix expected_output = {{""}};
        const Matrix output = solution.groupAnagrams(strs);

        Assert::matrix_equals(output, expected_output);
    }
    {
        std::vector<std::string> strs = {"a"};

        const Matrix expected_output = {{"a"}};
        const Matrix output = solution.groupAnagrams(strs);

        Assert::matrix_equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
