/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/
#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (left && right)
        {
            return left->val == right->val && isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        }
        return !left && !right;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({1, 2, 2, 3, 4, 4, 3});

        bool expected_output = true;
        bool output = solution.isSymmetric(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, 2, 2, {}, 3, {}, 3});

        bool expected_output = false;
        bool output = solution.isSymmetric(root);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
