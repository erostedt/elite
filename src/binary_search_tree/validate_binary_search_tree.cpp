/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <iostream>
#include <limits>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    void inorder(TreeNode *root, TreeNode *&prev, bool &is_bst)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, prev, is_bst);

        if (!is_bst || (prev && prev->val >= root->val))
        {
            is_bst = false;
            return;
        }
        prev = root;

        inorder(root->right, prev, is_bst);
    }

    bool isValidBST(TreeNode *root)
    {
        bool is_bst = true;
        TreeNode *prev = nullptr;
        inorder(root, prev, is_bst);
        return is_bst;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({2, 1, 3});
        const bool expected_output = true;
        const bool output = solution.isValidBST(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({5, 1, 4, {}, {}, 3, 6});
        const bool expected_output = false;
        const bool output = solution.isValidBST(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({2, 2, 2});
        const bool expected_output = false;
        const bool output = solution.isValidBST(root);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
