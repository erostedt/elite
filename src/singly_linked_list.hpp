#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

inline ListNode *singly_linked_list(const std::vector<int> &vec)
{
    if (vec.empty())
    {
        return nullptr;
    }

    ListNode *root = new ListNode(vec.front());
    ListNode *curr = root;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        curr->next = new ListNode(vec[i]);
        curr = curr->next;
    }
    return root;
}

inline ListNode *tail(ListNode *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

inline ListNode *index(ListNode *head, int index)
{
    if (index < 0)
    {
        return nullptr;
    }
    for (int i = 0; i < index && head; ++i)
    {
        head = head->next;
    }
    return head;
}

inline void print_list(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << ' ';
        head = head->next;
    }
    std::cout << '\n';
}
