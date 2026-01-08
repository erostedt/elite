/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two
different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
*/

#include <climits>
#include <iostream>
#include <limits>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    void inorder(TreeNode *root, TreeNode *&prev, int &min_diff)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, prev, min_diff);

        if (prev)
        {
            min_diff = min(min_diff, root->val - prev->val);
        }
        prev = root;

        inorder(root->right, prev, min_diff);
    }

    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        int minDiff = numeric_limits<int>::max();
        inorder(root, prev, minDiff);
        return minDiff;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({4, 2, 6, 1, 3});
        const int expected_output = 1;
        const int output = solution.getMinimumDifference(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, 0, 48, {}, {}, 12, 49});
        const int expected_output = 1;
        const int output = solution.getMinimumDifference(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({236, 104, 701, {}, 227, {}, 911});
        const int expected_output = 9;
        const int output = solution.getMinimumDifference(root);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, {}, 2});
        const int expected_output = 1;
        const int output = solution.getMinimumDifference(root);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
