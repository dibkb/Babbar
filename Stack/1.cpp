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
            while(!st.empty() && st.top() > nums[i]){
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
void printPrevSmall(vector<int>nums){
    stack<pair<int,int>> st;
    st.push({-1,-1});
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int curr = nums[i];
        int cnt = 0;
        while (st.top().first > curr)
        {
            cnt++;
            st.pop();
        }
        pair<int, int> prev;
        prev = st.top();
        if(prev.first == -1){
            ans = max(
                ans,
                curr * 1);
        }
        else
        {
            int maxi = max(
                prev.first * (i - prev.second + 1),
                curr * 1);
            ans = max(ans, maxi);
        }
        // cout << prev.first <<" ";
        cout << prev.first <<" " <<prev.second <<endl;
        pair<int, int> p;
        p.first = curr;
        p.second = i;
        st.push(p);
    }
    // cout << ans;
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
    printPrevSmall({2,1,2});
    return 0;
}
