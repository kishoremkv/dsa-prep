// leetcode url: https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int rem_sum = 0;
        rem_sum= accumulate(nums.begin(), nums.end(), rem_sum);

        vector<vector<int>> dp(nums.size(), vector<int>(rem_sum+1, -1));

        cout<<rem_sum<<endl;
        return dfs(0, rem_sum, nums, 0, dp);
    }

    bool dfs(int cur_sum, int rem_sum, vector<int>& nums, int ind, vector<vector<int>>& dp)
    {
        if(ind == nums.size()) return false;
        if(dp[ind][rem_sum] != -1)
            return dp[ind][rem_sum];
        if(cur_sum == rem_sum) return true;

        return dp[ind][rem_sum] = dfs(cur_sum + nums[ind], rem_sum - nums[ind], nums, ind+1, dp) ||
        dfs(cur_sum, rem_sum, nums, ind+1, dp);
    }
};
