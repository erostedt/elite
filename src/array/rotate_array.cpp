/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return;
        }

        const int rotations = k % nums.size();
        std::rotate(rbegin(nums), rbegin(nums) + rotations, rend(nums));
    }
};

int main()
{
    Solution solution;
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        const int k = 3;

        vector<int> expected_output = {5, 6, 7, 1, 2, 3, 4};
        solution.rotate(nums, k);

        Assert::equals(nums, expected_output);
    }
    {
        vector<int> nums = {-1, -100, 3, 99};
        const int k = 2;

        vector<int> expected_output = {3, 99, -1, -100};
        solution.rotate(nums, k);

        Assert::equals(nums, expected_output);
    }
    cout << "All passed" << endl;
}
