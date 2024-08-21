/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>

#include "assert.hpp"

using namespace std;

size_t first_diff(std::string_view str, std::string_view other)
{
    size_t min = std::min(std::size(str), std::size(other));
    for (size_t i = 0; i < min; ++i)
    {
        if (str[i] != other[i])
        {
            return i;
        }
    }
    return min;
}

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        std::string_view prefix = strs.front();
        size_t size = std::size(prefix);
        for (size_t i = 1; i < std::size(strs); ++i)
        {
            size = first_diff(prefix, strs[i]);
            prefix = prefix.substr(0, size);
        }
        return std::string(prefix);
    }
};

int main()
{
    Solution solution;
    {
        std::vector<std::string> strs = {"flower", "flow", "flight"};

        const std::string expected_output = "fl";
        const std::string output = solution.longestCommonPrefix(strs);

        Assert::equals(output, expected_output);
    }
    {
        std::vector<std::string> strs = {"dog", "racecar", "car"};

        const std::string expected_output = "";
        const std::string output = solution.longestCommonPrefix(strs);

        Assert::equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
