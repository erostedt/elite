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
#include <sstream>

#include "assert.hpp"

using namespace std;

void sink_row(std::ostringstream &io_sink, const int current_row, std::string_view str, const int num_rows)
{
    const int period = 2 * (num_rows - 1);
    if (current_row == 0 || current_row == num_rows - 1)
    {
        auto view = std::ranges::views::stride(str.substr(current_row), period);
        for (const auto ch : view)
        {
            io_sink << ch;
        }
        return;
    }

    auto view = std::ranges::views::stride(str.substr(current_row), period);
    auto second_view = std::ranges::views::stride(str.substr(period - current_row), period);
    auto zipped = std::ranges::views::zip(view, second_view);
    for (const auto [ch1, ch2] : zipped)
    {
        io_sink << ch1 << ch2;
    }
    if (std::ranges::size(view) > std::ranges::size(second_view))
    {
        io_sink << view.back();
    }
}

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
        {
            return s;
        }
        std::ostringstream sink;
        for (int i = 0; i < numRows; ++i)
        {
            sink_row(sink, i, s, numRows);
        }
        return sink.str();
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
