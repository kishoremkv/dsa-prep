// leetcode url: https://leetcode.com/problems/edit-distance/description/
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        return  dfs(0, 0, word1, word2);
    }

    int dfs(int i, int j, string& word1, string& word2)
    {
        if(i == word1.size() || j == word2.size()) 
        {
            // cout<<i<<" "<<j<<endl;
            return max((word1.size() - i), (word2.size() - j));

        }
        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
        {
            dp[i][j] = dfs(i+1, j+1, word1, word2);
        }
        else
        {
            dp[i][j] = min(min(1 + dfs(i+1, j+1, word1, word2), 
                            1 + dfs(i+1, j, word1, word2)),
                            1 + dfs(i, j+1, word1, word2));
        }

        return dp[i][j];
    }
};
