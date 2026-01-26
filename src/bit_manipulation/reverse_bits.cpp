/*
Reverse bits of a given 32 bits signed integer.



Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
Example 2:

Input: n = 2147483644

Output: 1073741822

Explanation:

Integer	Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110


Constraints:

0 <= n <= 231 - 2
n is even.


Follow up: If this function is called many times, how would you optimize it?
 */

#include "assert.hpp"
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int reverseBits(int n)
    {
        bitset<sizeof(int) * 8> bits(n);
        auto chars = bits.to_string();
        reverse(begin(chars), end(chars));
        return stoi(chars, 0, 2);
    }
};

int main()
{

    Solution solution;

    {
        const int a = 43261596;
        const int expected_output = 964176192;
        const int output = solution.reverseBits(a);

        Assert::equal(output, expected_output);
    }

    {
        const int a = 2147483644;
        const int expected_output = 1073741822;
        const int output = solution.reverseBits(a);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
