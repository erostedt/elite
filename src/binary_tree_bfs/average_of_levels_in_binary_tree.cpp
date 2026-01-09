/*
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers
within 10-5 of the actual answer will be accepted.


Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> averages{};

        queue<pair<TreeNode *, int>> q{};
        q.push({root, 0});
        int current_depth = 0;
        int current_count = 0;
        double sum = 0;
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
                averages.push_back(sum / current_count);
                sum = 0;
                current_count = 0;
                current_depth = depth;
            }
            sum += (double)node->val;
            ++current_count;

            q.push({node->right, depth + 1});
            q.push({node->left, depth + 1});
        }

        if (current_count != 0)
        {
            averages.push_back(sum / current_count);
        }
        return averages;
    }
};

int main()
{
    Solution solution;

    {
        TreeNode *root = binary_tree({3, 9, 20, {}, {}, 15, 7});
        const vector<double> expected_output = {3.00000, 14.50000, 11.00000};
        const vector<double> output = solution.averageOfLevels(root);

        Assert::all_close(output, expected_output);
    }

    {
        TreeNode *root = binary_tree({3, 9, 20, 15, 7});
        const vector<double> expected_output = {3.00000, 14.50000, 11.00000};
        const vector<double> output = solution.averageOfLevels(root);

        Assert::all_close(output, expected_output);
    }

    cout << "All passed" << endl;
}
