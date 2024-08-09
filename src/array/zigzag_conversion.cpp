/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

#include <iostream>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;
    {
        std::string s = "PAYPALISHIRING";
        const int numRows = 3;

        const std::string expected_output = "PAHNAPLSIIGYIR";
        const std::string output = solution.convert(s, numRows);

        Assert::equals(output, expected_output);
    }
    {
        std::string s = "PAYPALISHIRING";
        const int numRows = 4;

        const std::string expected_output = "PINALSIGYAHRPI";
        const std::string output = solution.convert(s, numRows);

        Assert::equals(output, expected_output);
    }

    std::cout << "All passed" << std::endl;
}
