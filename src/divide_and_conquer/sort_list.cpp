/*
Given the head of a linked list, return the list after sorting it in ascending order.


Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

#include "singly_linked_list.hpp"

#include "assert.hpp"

using namespace std;
class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        ListNode *list = singly_linked_list({4, 2, 1, 3});

        ListNode *expected_output = singly_linked_list({1, 2, 3, 4});
        ListNode *output = solution.sortList(list);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *list = singly_linked_list({-1, 5, 3, 4, 0});

        ListNode *expected_output = singly_linked_list({-1, 0, 3, 4, 5});
        ListNode *output = solution.sortList(list);

        Assert::equals(output, expected_output);
    }

    {
        ListNode *list = singly_linked_list({});

        ListNode *expected_output = singly_linked_list({});
        ListNode *output = solution.sortList(list);

        Assert::equals(output, expected_output);
    }

    cout << "All passed" << endl;
}
