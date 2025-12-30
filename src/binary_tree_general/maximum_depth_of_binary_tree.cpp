/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf
node.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2


Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({3, 9, 20, {}, {}, 15, 7});

        int expected_output = 3;
        int output = solution.maxDepth(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, {}, 2});

        int expected_output = 2;
        int output = solution.maxDepth(root);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
