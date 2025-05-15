// leetcode url - https://leetcode.com/problems/longest-palindromic-subsequence/
// TC - O(N^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(), s.end());

        // vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1)); -- topdown
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));

        for(int i = 1; i<=s.size();i++)
        {
            for(int j=1;j<=s.size();j++)
            {
                // if(i==0|| j==0)
                // {
                //     dp[i][j] = (r[i] == s[j]);
                //     continue;
                // }
                if(r[i-1] == s[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][s.size()];
        // return dfs(r, s, s.size()-1, s.size()-1, dp); // top down
    }

    int dfs(string& r, string& s, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(r[i] == s[j])
        {
            return dp[i][j] = 1 + dfs(r, s, i-1, j-1, dp);
        }
        else
        {
            return dp[i][j] = max(dfs(r, s, i-1, j, dp), dfs(r, s, i, j-1, dp));
        }
    }
};
