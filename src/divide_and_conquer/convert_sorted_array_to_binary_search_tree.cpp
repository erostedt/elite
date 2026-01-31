/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary
search tree.



Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#include <iostream>
#include <vector>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        vector<int> nums = {-10, -3, 0, 5, 9};

        TreeNode *expected_output = binary_tree({0, -3, 9, -10, {}, 5});
        TreeNode *output = solution.sortedArrayToBST(nums);

        Assert::equal(output, expected_output);
    }

    {
        vector<int> nums = {1, 3};

        TreeNode *expected_output = binary_tree({3, 1});
        TreeNode *output = solution.sortedArrayToBST(nums);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
