/*
Given the root of a binary tree, invert the tree, and return its root.


Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    TreeNode *invertTree(TreeNode *root)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({4, 2, 7, 1, 3, 6, 9});

        TreeNode *expected_output = binary_tree({4, 7, 2, 9, 6, 3, 1});
        TreeNode *output = solution.invertTree(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({2, 1, 3});

        TreeNode *expected_output = binary_tree({2, 3, 1});
        TreeNode *output = solution.invertTree(root);

        Assert::equal(output, expected_output);
    }
    {
        TreeNode *root = binary_tree({});

        TreeNode *expected_output = binary_tree({});
        TreeNode *output = solution.invertTree(root);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
