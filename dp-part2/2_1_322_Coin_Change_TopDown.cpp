// leetcode url: https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // DO THE bruteforce 
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        long long res = dfs(0, coins, amount, dp);
        return  res >= INT_MAX ? -1 : res;
        
    }

    long long dfs(int cur_ind, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(cur_ind == coins.size() ) return INT_MAX;
        if(dp[cur_ind][amount] != 0) return dp[cur_ind][amount];
        return dp[cur_ind][amount] = min(1 + dfs(cur_ind, coins, amount - coins[cur_ind], dp), dfs(cur_ind+1, coins, amount, dp));
    }
};
