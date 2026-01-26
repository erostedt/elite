/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the
single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-2^31 <= nums[i] <= 2^31 - 1
Each element in nums appears exactly three times except for one element which appears once.
 */

#include "assert.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int a{0}, b{0};
        for_each(begin(nums), end(nums), [&](int num) {
            a = ((a ^ num) & ~b);
            b = ((b ^ num) & ~a);
        });
        return a;
    }
};

int main()
{

    Solution solution;

    {
        vector nums = {2, 2, 3, 2};
        const int expected_output = 3;
        const int output = solution.singleNumber(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {0, 1, 0, 1, 0, 1, 99};
        const int expected_output = 99;
        const int output = solution.singleNumber(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
