//leetcode url: https://leetcode.com/problems/longest-common-subsequence/description/
// used Top down approach - Memoization 
// Gave TLE when I didn't pass the parameters as pass by reference
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        return dfs(text1, text2, 0, 0, dp);     
    }

    int dfs(string &text1, string &text2, int i, int j, vector<vector<int>>& dp)
    {
        if(i==text1.size() || j == text2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + dfs(text1, text2, i+1, j+1, dp);
        }
        else
        {
            return dp[i][j] = max(dfs(text1, text2, i+1, j, dp), dfs(text1, text2, i, j+1, dp));
        }
    }
};
