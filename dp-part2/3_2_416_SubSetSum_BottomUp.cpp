// leetcode url: https://leetcode.com/problems/partition-equal-subset-sum/description/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int rem_sum = 0;
        rem_sum= accumulate(nums.begin(), nums.end(), rem_sum);
        if(rem_sum%2 == 1) return false;
        rem_sum = rem_sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(rem_sum+1, 0));

        for(int i=0;i<nums.size();i++)
        {
            dp[i][0] = true;
        }

        for(int j=0;j<rem_sum+1; j++)
        {
            if(nums[0] == j) 
            dp[0][j] = true;
        }

        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<rem_sum + 1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(nums[i]<=j)
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
            }
        }

        return dp[nums.size()-1][rem_sum];

        // can I make the

        // cout<<rem_sum<<endl;
        // return dfs(0, rem_sum, nums, 0, dp);
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
