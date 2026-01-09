/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you
can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []



Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> right_side_view{};
        right_side_view.reserve(100);

        queue<pair<TreeNode *, int>> q{};
        int current_depth = -1;
        q.push({root, 0});
        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();

            if (!node)
            {
                continue;
            }
            if (depth != current_depth)
            {
                right_side_view.push_back(node->val);
                current_depth = depth;
            }

            q.push({node->right, depth + 1});
            q.push({node->left, depth + 1});
        }
        return right_side_view;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({1, 2, 3, {}, 5, {}, 4});
        const vector<int> expected_output = {1, 3, 4};
        const vector<int> output = solution.rightSideView(root);

        Assert::equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, 2, 3, 4, {}, {}, {}, 5});
        const vector<int> expected_output = {1, 3, 4, 5};
        const vector<int> output = solution.rightSideView(root);

        Assert::equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({1, {}, 3});
        const vector<int> expected_output = {1, 3};
        const vector<int> output = solution.rightSideView(root);

        Assert::equals(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({});
        const vector<int> expected_output = {};
        const vector<int> output = solution.rightSideView(root);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
