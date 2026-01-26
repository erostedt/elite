/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1



Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
 */

#include "assert.hpp"
#include <functional>
#include <iostream>
#include <numeric>

using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(begin(nums), end(nums), 0, bit_xor<>{});
    }
};

int main()
{

    Solution solution;

    {
        vector nums = {2, 2, 1};
        const int expected_output = 1;
        const int output = solution.singleNumber(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {4, 1, 2, 1, 2};
        const int expected_output = 4;
        const int output = solution.singleNumber(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {1};
        const int expected_output = 1;
        const int output = solution.singleNumber(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
