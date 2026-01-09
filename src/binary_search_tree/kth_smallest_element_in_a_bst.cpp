/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of
the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
*/

#include <iostream>
#include <limits>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;
class Solution
{
  public:
    void inorder(TreeNode *root, int &visited, int &smallest, int k)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, visited, smallest, k);
        ++visited;
        if (visited == k)
        {
            smallest = min(root->val, smallest);
            return;
        }
        inorder(root->right, visited, smallest, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int visited = 0;
        int smallest = numeric_limits<int>::max();
        inorder(root, visited, smallest, k);
        return smallest;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({3, 1, 4, {}, 2});
        const int k = 1;
        const int expected_output = 1;
        const int output = solution.kthSmallest(root, k);

        Assert::equal(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({5, 3, 6, 2, 4, {}, {}, 1});
        const int k = 3;
        const int expected_output = 3;
        const int output = solution.kthSmallest(root, k);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
