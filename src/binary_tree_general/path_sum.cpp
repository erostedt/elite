/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that
adding up all the values along the path equals targetSum.

A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/

#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    bool is_leaf(TreeNode *root)
    {
        return root && !root->left && !root->right;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (is_leaf(root) && targetSum == root->val)
        {
            return true;
        }
        if (!root || is_leaf(root))
        {
            return false;
        }

        int target = targetSum - root->val;
        return hasPathSum(root->left, target) || hasPathSum(root->right, target);
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({5, 4, 8, 11, {}, 13, 4, 7, 2, {}, {}, {}, 1});
        int target_sum = 22;

        const bool expected_output = true;
        const bool output = solution.hasPathSum(root, target_sum);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, 2, 3});
        int target_sum = 5;

        const bool expected_output = false;
        const bool output = solution.hasPathSum(root, target_sum);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({});
        int target_sum = 0;

        const bool expected_output = false;
        const bool output = solution.hasPathSum(root, target_sum);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
