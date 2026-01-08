#include "assert.hpp"
#include <deque>
#include <iostream>
#include <optional>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

inline TreeNode *binary_tree(const std::vector<std::optional<int>> &items, size_t index = 0)
{
    if (index >= items.size() || !items[index].has_value())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(*items[index]);
    root->left = binary_tree(items, 2 * index + 1);
    root->right = binary_tree(items, 2 * index + 2);
    return root;
}

inline void print_tree(TreeNode *root, size_t level = 0)
{
    if (!root)
    {
        return;
    }

    print_tree(root->right, level + 1);
    for (size_t i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << root->val << '\n';
    print_tree(root->left, level + 1);
}

inline std::vector<int> to_vector(TreeNode *root)
{
    if (!root)
    {
        return {};
    }

    std::vector<int> v{};
    std::deque<TreeNode *> q = {root};
    while (!q.empty())
    {
        auto node = q.front();
        q.pop_front();
        if (node)
        {
            v.push_back(node->val);
            q.push_back(node->left);
            q.push_back(node->right);
        }
    }
    return v;
}

namespace Assert
{

inline void equals(TreeNode *lhs, TreeNode *rhs)
{
    equals(::to_vector(lhs), ::to_vector(rhs));
}
}; // namespace Assert
