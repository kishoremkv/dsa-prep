// leetcode url: https://leetcode.com/problems/word-break/description/

class Solution {
public:
vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);
        return dfs(s, wordDict, 0);
    }

    bool dfs(string s, vector<string>& dict, int ind)
    {
        cout<<ind<<" "<<s<<endl;
        if(ind == s.size()) return true;
        if(dp[ind] !=-1) return dp[ind];
        bool ans = false;
        for(int i=0;i<dict.size();i++)
        {
            if(dict[i].size() > s.size() - ind || dict[i] != s.substr(ind, dict[i].size()))
            {
                continue;
            }
            else if(dfs(s, dict, ind+dict[i].size())) return dp[ind] = true;
            else;
        }
        return dp[ind] = false; 
    }

};
