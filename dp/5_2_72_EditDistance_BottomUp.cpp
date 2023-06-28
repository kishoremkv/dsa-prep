// leetcode url: https://leetcode.com/problems/edit-distance/submissions/981271660/
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1, vector<int>(word2.size()+1, 0));

        for(int i=1; i<=word1.size(); i++)
        {
            dp[i][0] = i;
        }

        
        for(int i=1; i<=word2.size(); i++)
        {
            dp[0][i] = i;
        }

        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[word1.size()][word2.size()];

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
