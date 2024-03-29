#include<iostream>
#include <stack>
using namespace std;
// class Car{
//     public:
//         int position;
//         int speed;
//         Car(int pos,int sp){
//             this->position = pos;
//             this->speed = sp;
//         }
// };
// bool compareCustomData(const Car& a, const Car& b) {
//     return a.speed < b.speed;
// }
// vector<double> nextSmaller(vector<vector<int>> nums){
//     stack<int> st;
//     int n = nums.size();
//     vector<double> res(n,-1);
//     for (int i = n - 1; i >= 0; --i)
//     {
//         while(!st.empty() && nums[i][1] <= nums[st.top()][1]){
//             st.pop();
//         }
//             // st.top() gives index of the next slowest car to the right
//         while(!st.empty()){
//             int topIdx = st.top();
//             int m1 = nums[i][0];
//             int m2 = nums[i][1];
//             int n1 = nums[st.top()][0];
//             int n2 = nums[st.top()][1];
//             double time = (n1 - m1) / (double)(m2 - n2);
//             if(res[st.top()] == -1 || time <= res[st.top()]){
//                 res[i] = time;
//                 break;
//             }
//             st.pop();
//         }
//         st.push(i);
//     }
//     return res;
// }
int longestValidParentheses(string s){
    int ans = 0;
    stack<char> st;
    st.push(-1);
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] == ')'){
            st.pop();
            if(!st.empty() && st.top()){
                ans = max(ans, i - st.top());
            }else{
                st.push(i);
            }
        }
        else{
            st.push(i);
        }
    }
    return ans;
}
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({s[0], 1});
        for (int i = 1; i < s.size(); ++i)
        {
            pair<char, int> top = st.top();
            if (top.first == s[i])
            {
                st.pop();
                st.push({top.first, top.second++});
            }else{
                st.push({s[i], 1});
            }
            if(top.second == k)
                st.pop();
        }
        string ans;
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main()
{
    // vector<vector<int>> cars = { { 1, 2 }, { 2, 1 }, { 4, 3 }, { 7, 2 } };
    // vector<vector<int>> cars = { { 3, 4 }, { 5, 4 }, { 6, 3 }, { 9, 1 } };
    // vector<double> nums = nextSmaller(cars);
    cout << removeDuplicates("abcccccfffdd",2);
    // for (auto i : nums) cout << i << " ";
    return 0;
}