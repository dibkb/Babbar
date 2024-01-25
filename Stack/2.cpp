#include <stack>
#include <iostream>
using namespace std;
vector<int> nextGreatestToRight(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    st.push(nums[n - 1]);
    vector<int> result(n);
    for (int i = n - 1; i >= 0; --i){
        if(i == n-1){
            st.push(n - 1);
            result[i] = n-1;
        }else{
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(i);
            }else{
                result[i] = i;
                st.push(i);

            }

        }
    }
    return result;
}
vector<int> nextGreatestToLeft(vector<int>nums){
    stack<int> st;
    int n = nums.size();
    st.push(nums[n - 1]);
    vector<int> result(n);
    for (int i = 0; i < n; ++i){
        if(i == 0){
            st.push(0);
            result[i] = 0;
        }else{
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top();
                st.push(i);
            }else{
                result[i] = i;
                st.push(i);

            }

        }
    }
    return result;
}
// int carFleet(int target, vector<int>& position, vector<int>& speed) {
//     stack<int> st;
//     int n = position.size();
//     int fleet = 0;
//     for (int i = 0; i < n; ++i){
//         if (!st.empty()){
//             int topIdx = st.top();
//             if(position[idx] > position[i]){
//                 // new car staring from last
//                 int timeNew = (target - position[i]) / speed[i];
//             }
//             else
//             {
//                 // new car starting from first
//             }
//         }
//         else
//         {
//             st.push(i);
//             fleet++;
//         }
//     }
// }
vector<int>calculateTimeTillFinish(vector<int>&position,vector<int>&speed, int& target){
    vector<int> result(speed.size());
    for (int i = 0; i < result.size(); ++i){
        result[i] = (target - position[i]) / speed[i];
    }
    return result;
}
vector<int>calculateGreatest(vector<int>&left,vector<int>&right,vector<int>&position){
    vector<int> greatest(right.size());
    for (int i = 0; i < right.size(); ++i){
        if(position[right[i]] > position[left[i]]){
            greatest[i] = right[i];
        }
        else
        {
            greatest[i] = left[i];
        }
    }
    return greatest;
}
int main(){
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;
    // calculate next greatest
    vector<int> time = calculateTimeTillFinish(position,speed,target);
    vector<int> right = nextGreatestToRight(position);
    vector<int>left = nextGreatestToLeft(position);
    vector<int> greatest = calculateGreatest(left,right,position);
    
        for (auto it : greatest)
        {
            cout << it << " ";
        }
    return 0;
}