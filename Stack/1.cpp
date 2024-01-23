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
using namespace std;
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    removeElement(st, 3);
    return 0;
}