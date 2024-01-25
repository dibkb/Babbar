#include <stack>
#include <iostream>
using namespace std;
// void removeElement(stack<int> &st, int k)
// {
//     if(k == 1)
//         return;
//     k--;
//     int temp = st.top();
//     cout << " K " << k;
//     cout << " temp " << temp;
//     st.pop();
//     removeElement(st, k);
//     st.push(temp);
// };
// void solve(stack<int> &st, int k,int num){
//     if(k == 0){
//         st.push(num);
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     solve(st, k - 1,num);
//     st.push(temp);
// }
// void insertAtBottom(stack<int> &st, int num){
//     int n = st.size();
//     solve(st, n, num);
// };
template <typename T>
void printStack(const std::stack<T>& myStack) {
    std::stack<T> tempStack = myStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    std::cout << std::endl;
}
// void insertBottom(stack<int> &st, int n){
//     if(st.empty()){
//         st.push(n);
//         return;
//     }
//     int temp = st.top();
//     st.pop();
//     insertBottom(st, n);
//     st.push(temp);
// }
// void reverseStack(stack<int> &st, int k){
//     if( k == 0)
//         return;
//     int temp = st.top();
//     st.pop();
//     reverseStack(st,k-1);
//     insertBottom(st, temp);
// };
// void insertSorted(stack<int> &st, int num){
//     if(st.empty()){
//         st.push(num);
//         return;
//     }
//     int temp = st.top();
//     if(temp < num){
//         st.push(num);
//         return;
//     }
//     st.pop();
//     insertSorted(st, num);
//     st.push(temp);
// };
// void sort(stack<int> &st){
//     if(st.size() == 1)
//         return;
//     int temp = st.top();
//     st.pop();
//     sort(st);
//     insertSorted(st, temp);
// }
void printNextSmall(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if(i == n-1){
            cout << -1<< " ";
            st.push(nums[i]);
        }else{
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                cout << -1 << " ";
            }
            else
            {
                cout << st.top() << " ";
            }
            st.push(nums[i]);
        }
    }
}
vector<int> prevSmall(vector<int>nums){
    stack<int> st;
    st.push(-1);
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); ++i)
    {
        int curr = nums[i];
        while(st.top() != -1 && nums[st.top()] >= curr){
            st.pop();
        }
        res[i] = st.top();
        st.push(i);
    }
    return res;
}
vector<int> nextSmall(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    st.push(n);
    vector<int> res(n);
    for (int i = n-1; i>= 0; --i)
    {
        int curr = nums[i];
        while(st.top() != n && nums[st.top()] > curr){
            st.pop();
        }
        res[i] = st.top();
        st.push(i);
    }
    return res;
}
vector<int> nextGreatest(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    st.push(nums[n - 1]);
    vector<int> result(n);
    for (int i = n - 1; i >= 0; --i){
        if(i == n-1){
            st.push(nums[n - 1]);
            result[i] = 0;
        }else{
            while(!st.empty() && nums[i] > st.top()){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(nums[i]);
            }else{
                result[i] = 0;
                st.push(nums[i]);

            }

        }
    }
    return result;
}
int main(){
    // stack<int> st;
    // st.push(100);
    // st.push(21);
    // st.push(31);
    // st.push(90);
    // st.push(50);
    // printStack(st);
    // sort(st);
    // printStack(st);
    // solve(st);
    vector<int> next = nextGreatest({2,7,4,3,5});
    for(auto it: next)
        cout << it << " ";
        return 0;
}
