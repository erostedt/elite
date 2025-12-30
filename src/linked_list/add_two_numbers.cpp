/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include "singly_linked_list.hpp"
#include <iostream>

using namespace std;
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *result = new ListNode();
        ListNode *head = result;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            if (sum > 9)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->val + carry;
            if (sum > 9)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head->next = new ListNode(sum);
            head = head->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + carry;
            if (sum > 9)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head->next = new ListNode(sum);
            head = head->next;
            l2 = l2->next;
        }
        if (carry == 1)
        {
            head->next = new ListNode(1);
        }
        return result->next;
    }
};

int main()
{
    Solution solution;

    {
        ListNode *l1 = singly_linked_list({2, 4, 3});
        ListNode *l2 = singly_linked_list({5, 6, 4});

        ListNode *expected_output = singly_linked_list({7, 0, 8});
        ListNode *output = solution.addTwoNumbers(l1, l2);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *l1 = singly_linked_list({0});
        ListNode *l2 = singly_linked_list({0});

        ListNode *expected_output = singly_linked_list({0});
        ListNode *output = solution.addTwoNumbers(l1, l2);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *l1 = singly_linked_list({9, 9, 9, 9, 9, 9, 9});
        ListNode *l2 = singly_linked_list({9, 9, 9, 9});

        ListNode *expected_output = singly_linked_list({8, 9, 9, 9, 0, 0, 0, 1});
        ListNode *output = solution.addTwoNumbers(l1, l2);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
