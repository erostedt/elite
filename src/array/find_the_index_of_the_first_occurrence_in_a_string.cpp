/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <iostream>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {

        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        std::string haystack = "sadbutsad";
        std::string needle = "sad";

        const int expected_output = 0;
        const int output = solution.strStr(haystack, needle);

        Assert::equal(output, expected_output);
    }
    {
        std::string haystack = "leetcode";
        std::string needle = "leeto";

        const int expected_output = -1;
        const int output = solution.strStr(haystack, needle);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
