/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        --k;
        nth_element(begin(nums), begin(nums) + k, end(nums), greater<int>{});
        return nums[k];
    }
};

int main()
{
    Solution solution;
    {
        vector nums = {3, 2, 1, 5, 6, 4};
        const int k = 2;

        const int expected_output = 5;
        const int output = solution.findKthLargest(nums, k);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        const int k = 4;

        const int expected_output = 4;
        const int output = solution.findKthLargest(nums, k);

        Assert::equal(output, expected_output);
    }

    {
        vector nums = {-1, 2, 0};
        const int k = 3;

        const int expected_output = -1;
        const int output = solution.findKthLargest(nums, k);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
