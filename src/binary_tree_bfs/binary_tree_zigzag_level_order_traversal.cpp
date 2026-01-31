/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to
right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

#include "assert.hpp"
#include "binary_tree.hpp"

using namespace std;

class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> levels{};
        if (!root)
        {
            return levels;
        }

        deque<TreeNode *> q{};
        q.push_back(root);
        bool reverse = false;
        while (!q.empty())
        {
            const size_t n = q.size();
            vector<int> level{};
            level.reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                if (reverse)
                {
                    const auto node = q.back();
                    q.pop_back();
                    level.push_back(node->val);
                    if (node->right)
                    {
                        q.push_front(node->right);
                    }
                    if (node->left)
                    {
                        q.push_front(node->left);
                    }
                }
                else
                {
                    const auto node = q.front();
                    q.pop_front();
                    level.push_back(node->val);
                    if (node->left)
                    {
                        q.push_back(node->left);
                    }
                    if (node->right)
                    {
                        q.push_back(node->right);
                    }
                }
            }
            reverse = !reverse;
            levels.push_back(std::move(level));
        }

        return levels;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({3, 9, 20, {}, {}, 15, 7});
        const vector<vector<int>> expected_output = {{3}, {20, 9}, {15, 7}};
        const vector<vector<int>> output = solution.zigzagLevelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1});
        const vector<vector<int>> expected_output = {{1}};
        const vector<vector<int>> output = solution.zigzagLevelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({});
        const vector<vector<int>> expected_output = {};
        const vector<vector<int>> output = solution.zigzagLevelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, 2, 3, 4, {}, {}, 5});
        const vector<vector<int>> expected_output = {{1}, {3, 2}, {4, 5}};
        const vector<vector<int>> output = solution.zigzagLevelOrder(root);

        Assert::matrix_equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
