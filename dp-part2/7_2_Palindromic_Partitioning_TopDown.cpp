// O^2 Solution but with auxilary space + O(n)
// geeksforgeeks url: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // dp;
    int palindromicPartition(string str)
    {
        // code here
        //ababbbabbababa
        // vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
        vector<int> dp(str.size(), -1); 
        
        // for(int i=0;i<str.size();i++)
        // {
        //     for(int j=0;j<str.size();j++)
        //     cout<<dp[i][j]<< " ";
        //     cout<<endl;
        // }
        // return dfs(0, str.size()-1, str, dp);
        return dfs2(0, str, dp)-1;
    }

    bool is_palin(string str)
    {
        int l=0, r=str.size()-1;
        while(l<r)
        {
            if(str[l++] != str[r--]) return false;
            
        }
        return true;
    }
    //o^2 algo
    int dfs2(int ind,string str, vector<int>& dp)
    {
        if(ind == str.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int min_ans = INT_MAX;
        for(int j = ind; j<str.size(); j++)
        {
            if(is_palin(str.substr(ind, j-ind+1)))
            {
                min_ans = min(min_ans, 1 + dfs2(j+1, str, dp));
            }
        }
        
        return dp[ind] = min_ans;
    }
    
    //o^3 algp
    int dfs(int l, int r, string str, vector<vector<int>>& dp)
    {
        
        int min_ans= INT_MAX;
        // cout<<dp[l][r]<<endl;
        if(dp[l][r] != -1)return dp[l][r];
        if(is_palin(str.substr(l, r-l+1)))
        {
            // cout<<l<<" --- "<<r<<endl;
            min_ans = 0;
        }
        else
        {
            // cout<<l<<" "<<r<<endl;
            for(int i = l; i < r; i++)
            {
                min_ans = min( min_ans , 1 + dfs(l, i, str, dp) + dfs(i+1, r, str, dp));    
            }
            // what can be done in this sceanrio? 
            
            // aba | bbbabbababa
            
        }
        
        return dp[l][r] = min_ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
