/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element
always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>

#include "assert.hpp"

using namespace std;

class Solution
{
  public:
    int majorityelement(vector<int> &nums)
    {
        int majority = 0;
        int count = 0;
        for (const int num : nums)
        {
            if (num == majority)
            {
                ++count;
            }
            else
            {
                --count;
            }
            if (count <= 0)
            {
                majority = num;
                count = 1;
            }
        }
        return majority;
    }
};

int main()
{
    Solution solution;
    {
        std::vector<int> nums = {3, 2, 3};

        const int expected_output = 3;
        const int output = solution.majorityelement(nums);

        Assert::equal(output, expected_output);
    }
    {
        std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

        const int expected_output = 2;
        const int output = solution.majorityelement(nums);

        Assert::equal(output, expected_output);
    }
    std::cout << "All passed" << std::endl;
}
