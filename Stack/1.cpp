#include <stack>
#include <iostream>
using namespace std;
void removeElement(stack<int> &st, int k)
{
    if(k == 1)
        return;
    k--;
    int temp = st.top();
    cout << " K " << k;
    cout << " temp " << temp;
    st.pop();
    removeElement(st, k);
    st.push(temp);
};
void solve(stack<int> &st, int k,int num){
    if(k == 0){
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k - 1,num);
    st.push(temp);
}
void insertAtBottom(stack<int> &st, int num){
    int n = st.size();
    solve(st, n, num);
};
template <typename T>
void printStack(const std::stack<T>& myStack) {
    std::stack<T> tempStack = myStack;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }

    std::cout << std::endl;
}
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    printStack(st);
    insertAtBottom(st,99);
    printStack(st);
    // solve(st);
    return 0;
}
