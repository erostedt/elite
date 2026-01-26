/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also
known as the Hamming weight).



Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.



Constraints:

1 <= n <= 2^31 - 1


Follow up: If this function is called many times, how would you optimize it?
 */

#include "assert.hpp"
#include <bit>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int hammingWeight(int n)
    {
        return popcount((unsigned)n);
    }
};

int main()
{

    Solution solution;

    {
        const int n = 11;
        const int expected_output = 3;
        const int output = solution.hammingWeight(n);

        Assert::equal(output, expected_output);
    }

    {
        const int n = 128;
        const int expected_output = 1;
        const int output = solution.hammingWeight(n);

        Assert::equal(output, expected_output);
    }

    {
        const int n = 2147483645;
        const int expected_output = 30;
        const int output = solution.hammingWeight(n);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
