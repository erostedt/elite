/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include "singly_linked_list.hpp"
#include <iostream>

using namespace std;
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode result;
        ListNode *head = &result;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                head->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                head->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            head = head->next;
        }
        while (list1)
        {
            head->next = new ListNode(list1->val);
            list1 = list1->next;
            head = head->next;
        }
        while (list2)
        {
            head->next = new ListNode(list2->val);
            list2 = list2->next;
            head = head->next;
        }
        return result.next;
    }
};

int main()
{
    Solution solution;

    {
        ListNode *l1 = singly_linked_list({1, 2, 4});
        ListNode *l2 = singly_linked_list({1, 3, 4});

        ListNode *expected_output = singly_linked_list({1, 1, 2, 3, 4, 4});
        ListNode *output = solution.mergeTwoLists(l1, l2);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *l1 = singly_linked_list({});
        ListNode *l2 = singly_linked_list({});

        ListNode *expected_output = singly_linked_list({});
        ListNode *output = solution.mergeTwoLists(l1, l2);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *l1 = singly_linked_list({});
        ListNode *l2 = singly_linked_list({0});

        ListNode *expected_output = singly_linked_list({0});
        ListNode *output = solution.mergeTwoLists(l1, l2);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
