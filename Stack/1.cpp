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
void insertSorted(stack<int> &st, int num){
    if(st.empty()){
        st.push(num);
        return;
    }
    int temp = st.top();
    if(temp < num){
        // base case;
        st.push(num);
        return;
    }
    st.pop();
    insertSorted(st, num);
    st.push(temp);
};
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    printStack(st);
    insertSorted(st, 2);
    printStack(st);
    // solve(st);
    return 0;
}
