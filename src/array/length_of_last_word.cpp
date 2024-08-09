/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
 consisting of non-space characters only.



Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        std::ranges::reverse(s);
        std::istringstream iss(s);
        std::string last_word;
        iss >> last_word;
        return std::size(last_word);
    }
};

int main()
{
    Solution solution;
    {
        const std::string str = "Hello World";

        const int expected_output = 5;
        const int output = solution.lengthOfLastWord(str);

        Assert::equal(output, expected_output);
    }
    {
        const std::string str = "   fly me   to   the moon  ";

        const int expected_output = 4;
        const int output = solution.lengthOfLastWord(str);

        Assert::equal(output, expected_output);
    }
    {
        const std::string str = "luffy is still joyboy";

        const int expected_output = 6;
        const int output = solution.lengthOfLastWord(str);

        Assert::equal(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
