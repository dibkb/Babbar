    #include <iostream>
    using namespace std;


        // void backtradk(int n){
        //     if( n < 0)
        //         return;
        //     if (n == 0)
        //     {
        //         res++;
        //         return;
        //     }
        //     for(int i = 1; i <= 2; ++i){
        //         backtradk(n - i);
        //     }
        // }
        // int climbStairs(int n) {
        //     backtradk(n);
        //     return res;
        // }
        // ----------------
        
        // int res = INT_MAX;
        // void backtrack(vector<int>& coins, int idx, int amount){
        //     // base case;
        //     if(amount <= 0){
        //         if(amount == 0){
        //             // ans;
        //             res = min(res,idx);
        //         }
        //         return;
        //     };
        //     for(int i = 0; i < coins.size(); ++i){
        //         int coin = coins[i];
        //         if(amount - coin >= 0){
        //             backtrack(coins,idx+1,amount-coin);
        //         }
        //     }
        // }
        // int coinChange(vector<int> coins, int amount) {
        //     backtrack(coins,0,amount);
        //     return res == INT_MAX ? -1 :res;
        // }

        // -------------------
        // void backtrack(vector<int> nums, int idx,vector<int> temp){
        //     if(idx == nums.size()){
        //         for(auto it:temp){
        //             cout << it << " ";
        //         }
        //         cout << endl;
        //         return;
        //     }
        //     temp.emplace_back(nums[idx]);
        //     backtrack(nums, idx + 1, temp);
        //     temp.pop_back();
        //     backtrack(nums, idx + 1, temp);

        // }

        // void backtrack(vector<int> nums, int idx,vector<int> temp){
        //     if(idx > nums.size()){
        //         return;
        //     }
        //     for(auto it:temp){
        //             cout << it << " ";
        //     }
        //     cout << endl;
        //     // for (int i = idx; i <= idx;++i){
        //     //     temp.emplace_back(nums[i]);
        //     //     backtrack(nums, i + 1, temp);
        //     //     temp.pop_back();

        //     // }
        //     for(int i = idx; i < nums.size(); i++){
        //         // if(i > idx && nums[i] == nums[i-1]) continue;
        //         temp.emplace_back(nums[i]);
        //         backtrack(nums,i+1,temp);
        //         temp.pop_back();
        //     }
        // }

        // void printAllSubarrays(vector<int> nums){
        //     backtrack(nums, 0,{});
        // }
    // void backtrack(int index, string s, string curr,string part){
    //     if(index == s.size()){
    //         return;
    //     }
    //     // cout << curr <<endl;
    //     for (int i = index; i < s.size(); i++)
    //     {
    //         string str = s.substr(index, i - index + 1);
    //         if(str == part){
    //             backtrack(i + 1, s, curr, part);
    //         }
    //         else if (str.find(part) != std::string::npos) {
    //             continue;
    //         }else{
    //             backtrack(i + 1, s, curr + str, part);
    //         }
    //     }
    // }
    // string res;
    // void backtrack(string&s, string& part)
    // {
    //     if(s.find(part) == std::string::npos){
    //         // not in part;
    //         return;
    //     }
    //     for (int i = 0; i < s.size(); ++i){
    //         string sub = s.substr(i, part.size());
    //         // cout << sub<<" " << i << endl;
    //         if (sub == part)
    //         {
    //             s.erase(i, part.size());
    //             backtrack(s, part);
    //         }
    //         else
    //             continue;
    //     }
    // }

    // void removeOccurrences(string& s, string & part)
    // {
    //     backtrack(s,part);
    // }
    // -----------possible dearrangement-----------
    void dearrangement(vector<int> nums, int idx, vector<int> temp){
        //  --------------base case------------
        if(idx >= nums.size()){
            for(auto it: temp)
                cout << it << " ";
            cout << endl;
        }
        for (int i = idx; i < nums.size(); ++i)
        {
            swap(nums[idx], nums[i]);
            temp.emplace_back(nums[i]);
            dearrangement(nums, idx + 1, temp);
            swap(nums[idx], nums[i]);
            temp.pop_back();
        }
    };
    int main()
    {
        dearrangement({1,2,3}, 0, {});
        return 0;
    }