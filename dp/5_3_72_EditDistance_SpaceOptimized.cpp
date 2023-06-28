// leetcode: https://leetcode.com/problems/edit-distance/description/
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        dp.resize(2, vector<int>(word2.size()+1, 0));

        for(int i=0; i<=word2.size(); i++)
        {
            dp[0][i] = i;
        }

        for(int i=1;i<=word1.size();i++)
        {
            dp[1][0] = i;
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[1][j] = dp[0][j-1];
                else
                {
                    dp[1][j] = 1 + min({dp[0][j-1], dp[0][j], dp[1][j-1]});
                }
                cout<<dp[1][j]<<" ";
            }
            dp[0] = dp[1];
            cout<<endl;
        }
        return dp[0][word2.size()];

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

        if(word1[i-1] == word2[j-1])
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
