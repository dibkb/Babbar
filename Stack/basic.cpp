#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <typename T>
void printStack(const std::stack<T>& myStack) {
    std::stack<T> tempStack = myStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    std::cout << std::endl;
};
void insertAtBottom(stack<int>&nums, int val)
{
    if(nums.size()==0){
        nums.push(val);
        return;
    }
    int top = nums.top();
    nums.pop();
    insertAtBottom(nums, val);
    nums.push(top);
};
void reverseStack(stack<int> &nums)
{
    if(nums.size() == 1)
        return;
    int top = nums.top();
    nums.pop();
    reverseStack(nums);
    insertAtBottom(nums, top);
};
void reverseQueue(queue<int> & que){
    if(que.size() == 1) {
        return;
    }
    int front = que.front();
    que.pop();
    reverseQueue(que);
    que.push(front);
}
void printQueue(queue<int> & que){
    while (!que.empty()) {
        cout<< que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;
}
int main()
{
    // stack<int> v;
    // v.push(4);
    // v.push(3);
    // v.push(1);
    // v.push(2);
    queue<int> que;
    que.push(10);
    que.push(30);
    que.push(40);
    que.push(50);
    cout << endl;
    // printQueue(que);
    reverseQueue(que);
    printQueue(que);
    // while(!que.empty()){
    //     cout << que.front() <<" ";
    //     que.pop();
    // }
    return 0;
};