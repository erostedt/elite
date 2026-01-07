/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is
the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/
#include <iostream>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        vector<int> inorder = {9, 3, 15, 20, 7};
        vector<int> postorder = {9, 15, 7, 20, 3};

        TreeNode *expected_output = binary_tree({3, 9, 20, {}, {}, 15, 7});
        TreeNode *output = solution.buildTree(inorder, postorder);

        Assert::equal(output, expected_output);
    }

    {
        vector<int> inorder = {-1};
        vector<int> postorder = {-1};

        TreeNode *expected_output = binary_tree({-1});
        TreeNode *output = solution.buildTree(inorder, postorder);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
