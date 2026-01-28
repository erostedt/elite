/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

#include "assert.hpp"
#include <iostream>

using namespace std;

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{

    Solution solution;

    {
        vector nums = {10, 9, 2, 5, 3, 7, 101, 18};
        const int expected_output = 4;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {10, 9, 2, 5, 3, 7, 101, 18};
        const int expected_output = 4;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {7, 7, 7, 7, 7, 7, 7};
        const int expected_output = 1;
        const int output = solution.lengthOfLIS(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
