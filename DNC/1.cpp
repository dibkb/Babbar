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
    int res = INT_MAX;
    void backtrack(vector<int>& coins, int idx, int amount){
        // base case;
        if(amount <= 0){
            if(amount == 0){
                // ans;
                res = min(res,idx);
            }
            return;
        };
        for(int i = 0; i < coins.size(); ++i){
            int coin = coins[i];
            if(amount - coin >= 0){
                backtrack(coins,idx+1,amount-coin);
            }
        }
    }
    int coinChange(vector<int> coins, int amount) {
        backtrack(coins,0,amount);
        return res == INT_MAX ? -1 :res;
    }
int main(){
    coinChange({1, 2, 5}, 11);
    cout << res;
    return 0;
}