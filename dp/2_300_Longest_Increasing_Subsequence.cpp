//Leecode link: https://leetcode.com/problems/longest-increasing-subsequence/description/

//using dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max_ele = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            max_ele = 0;
            int cur_ind = -1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]>max_ele)
                {
                    max_ele = dp[j];
                    cur_ind = j;
                }
            }
            if(cur_ind !=-1)
            dp[i]+=dp[cur_ind];

            cout<<dp[i]<<" ";
        }

        return *max_element(dp.begin(), dp.end());
    }
};
