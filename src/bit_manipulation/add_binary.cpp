/*
Given two binary strings a and b, return their sum as a binary string.


Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
 */

#include "assert.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

class Solution
{
  public:
    inline pair<char, int> binary_carry(int sum)
    {
        switch (sum)
        {
        case 0:
            return make_pair('0', 0);
        case 1:
            return make_pair('1', 0);
        case 2:
            return make_pair('0', 1);
        case 3:
            return make_pair('1', 1);
        default:
            unreachable();
        }
    }

    string addBinary(string a, string b)
    {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));

        int carry = 0;
        auto ia = begin(a);
        auto ib = begin(b);
        ostringstream out{};
        for (; ia != end(a) && ib != end(b); ++ia, ++ib)
        {
            int va = *ia - '0';
            int vb = *ib - '0';
            auto [bit, new_carry] = binary_carry(va + vb + carry);
            out << bit;
            carry = new_carry;
        }

        for_each(ia, end(a), [&](const char c) {
            int v = c - '0';
            auto [bit, new_carry] = binary_carry(v + carry);
            out << bit;
            carry = new_carry;
        });

        for_each(ib, end(b), [&](const char c) {
            int v = c - '0';
            auto [bit, new_carry] = binary_carry(v + carry);
            out << bit;
            carry = new_carry;
        });

        if (carry > 0)
        {
            out << '1';
        }
        string res = out.str();
        reverse(begin(res), end(res));
        return res;
    }
};

int main()
{

    Solution solution;

    {
        const string a = "11";
        const string b = "1";
        const string expected_output = "100";
        const string output = solution.addBinary(a, b);

        Assert::equal(output, expected_output);
    }

    {
        const string a = "1010";
        const string b = "1011";
        const string expected_output = "10101";
        const string output = solution.addBinary(a, b);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
