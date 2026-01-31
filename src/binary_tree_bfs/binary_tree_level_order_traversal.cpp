/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level
by level).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <queue>
#include <utility>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levels{};

        queue<pair<TreeNode *, size_t>> q{};
        q.push({root, 0});
        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();

            if (!node)
            {
                continue;
            }

            if (levels.size() <= depth)
            {
                levels.emplace_back(vector<int>{node->val});
            }
            else
            {
                levels[depth].push_back(node->val);
            }

            q.push({node->left, depth + 1});
            q.push({node->right, depth + 1});
        }

        return levels;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({3, 9, 20, {}, {}, 15, 7});
        const vector<vector<int>> expected_output = {{3}, {9, 20}, {15, 7}};
        const vector<vector<int>> output = solution.levelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1});
        const vector<vector<int>> expected_output = {{1}};
        const vector<vector<int>> output = solution.levelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({});
        const vector<vector<int>> expected_output = {};
        const vector<vector<int>> output = solution.levelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
