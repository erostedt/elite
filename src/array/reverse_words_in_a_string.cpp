/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be
separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between
two words. The returned string should only have a single space separating the
words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single
space in the reversed string.


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it
in-place with O(1) extra space?

 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    string reverseWords(string s)
    {
        reverse(begin(s), end(s));
        istringstream input(s);
        ostringstream output{};
        string word;

        while (input >> word)
        {
            reverse(begin(word), end(word));
            output << word << ' ';
        }
        auto result = output.str();
        return (result.empty()) ? "" : result.substr(0, result.size() - 1);
    }
};

int main()
{
    Solution solution;
    {
        string s = "the sky is blue";

        string expected_output = "blue is sky the";
        string output = solution.reverseWords(s);

        Assert::equals(output, expected_output);
    }
    {
        string s = "  hello world  ";

        string expected_output = "world hello";
        string output = solution.reverseWords(s);

        Assert::equals(output, expected_output);
    }
    {
        string s = "a good   example";

        string expected_output = "example good a";
        string output = solution.reverseWords(s);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
