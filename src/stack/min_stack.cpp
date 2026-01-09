/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include "assert.hpp"
#include <iostream>
using namespace std;
class MinStack
{
    vector<pair<int, int>> stack{};

  public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.empty())
        {
            stack.push_back({val, val});
            return;
        }

        auto smallest = min(stack.back().second, val);
        stack.push_back({val, smallest});
    }

    void pop()
    {
        stack.pop_back();
    }

    int top()
    {
        return stack.back().first;
    }

    int getMin()
    {
        return stack.back().second;
    }
};

int main()
{
    MinStack obj{};
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    Assert::equal(-3, obj.getMin());
    obj.pop();
    Assert::equal(0, obj.top());
    Assert::equal(-2, obj.getMin());
    cout << "Success!" << endl;
}
