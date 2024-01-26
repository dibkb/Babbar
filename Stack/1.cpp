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
// void printNextSmall(vector<int>nums){
//     stack<int> st;
//     int n = nums.size();
//     for (int i = n - 1; i >= 0; --i)
//     {
//         if(i == n-1){
//             cout << -1<< " ";
//             st.push(nums[i]);
//         }else{
//             while(!st.empty() && st.top() >= nums[i]){
//                 st.pop();
//             }
//             if(st.empty()){
//                 cout << -1 << " ";
//             }
//             else
//             {
//                 cout << st.top() << " ";
//             }
//             st.push(nums[i]);
//         }
//     }
// }
// vector<int> prevSmall(vector<int>nums){
//     stack<int> st;
//     st.push(-1);
//     vector<int> res(nums.size());
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         int curr = nums[i];
//         while(st.top() != -1 && nums[st.top()] >= curr){
//             st.pop();
//         }
//         res[i] = st.top();
//         st.push(i);
//     }
//     return res;
// }
// vector<int> nextSmall(vector<int>nums){
//     stack<int> st;
//     int n = nums.size();
//     st.push(n);
//     vector<int> res(n);
//     for (int i = n-1; i>= 0; --i)
//     {
//         int curr = nums[i];
//         while(st.top() != n && nums[st.top()] > curr){
//             st.pop();
//         }
//         res[i] = st.top();
//         st.push(i);
//     }
//     return res;
// }
vector<int> nextGreatest(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    st.push(nums[n - 1]);
    vector<int> result(n);
    // for (int i = n - 1; i >= 0; --i){
    //     if(i == n-1){
    //         st.push(nums[n - 1]);
    //         result[i] = nums[n-1];
    //     }else{
    //         while(!st.empty() && nums[i] >= st.top()){
    //             st.pop();
    //         }
    //         if(!st.empty()){
    //             result[i] = st.top();
    //             st.push(nums[i]);
    //         }else{
    //             result[i] = nums[i];
    //             st.push(nums[i]);
    //         }

    //     }
    // }
        for (int i = 0; i < n; ++i) {
        // Pop elements from the stack until an element greater than the current element is found
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }
    cout << st.size() <<endl;
    return result;
}
// void inValidString(string s){
//     stack<char> st;
//     for(auto it:s){
//         if(st.size() >=2){
//             char last = st.top(); st.pop();
//             char secondLast = st.top(); st.pop();
//             if(2* last == (secondLast + it) ){
//                 continue;
//             }else{
//                 st.push(secondLast); st.push(last); st.push(it);
//             }
//         }else {
//             st.push(it);
//         }
//     }
//     for(auto it:st)
//         cout << it < " ";
// }
void astroidCollision(vector<int>s){
    stack<int> st;
    for(auto it : s){
        if(!st.empty()){
            if(st.top() > 0 && it<0)
            {
                while(!st.empty() && st.top() > 0 && st.top() < abs(it)){
                    st.pop();
                }
                if(!st.empty() && st.top()+it == 0){
                    st.pop();
                }else if(!st.empty() && st.top() < 0){
                    st.push(it);
                }else if(st.empty()) st.push(it);
            }
            else
            {
                st.push(it);
            }
        }else st.push(it);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.emplace_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans){
        cout << it << " ";
    }
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
    vector<int> ans = nextGreatest({12,6,7,1,1});
    for(auto i : ans)
        cout << i << " ";
    // astroidCollision({8,-8});
}
