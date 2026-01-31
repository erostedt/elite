/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

#include "assert.hpp"
#include "singly_linked_list.hpp"
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        NOT_IMPLEMENTED;
    }
};

int main()
{
    Solution solution;

    {
        vector<ListNode *> lists = {
            singly_linked_list({1, 4, 5}),
            singly_linked_list({1, 3, 4}),
            singly_linked_list({2, 6}),
        };

        ListNode *expected_output = singly_linked_list({1, 1, 2, 3, 4, 4, 5, 6});
        ListNode *output = solution.mergeKLists(lists);

        Assert::equal(output, expected_output);
    }

    {
        vector<ListNode *> lists = {};

        ListNode *expected_output = singly_linked_list({});
        ListNode *output = solution.mergeKLists(lists);

        Assert::equal(output, expected_output);
    }

    {
        vector<ListNode *> lists = {singly_linked_list({})};

        ListNode *expected_output = singly_linked_list({});
        ListNode *output = solution.mergeKLists(lists);

        Assert::equal(output, expected_output);
    }

    cout << "All passed" << endl;
}
