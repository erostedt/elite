/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is
the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/
#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};

        TreeNode *expected_output = binary_tree({3, 9, 20, {}, {}, 15, 7});
        TreeNode *output = solution.buildTree(preorder, inorder);

        Assert::equal(output, expected_output);
    }

    {
        vector<int> preorder = {-1};
        vector<int> inorder = {-1};

        TreeNode *expected_output = binary_tree({-1});
        TreeNode *output = solution.buildTree(preorder, inorder);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
