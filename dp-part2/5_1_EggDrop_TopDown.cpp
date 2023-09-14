//geeksforgeeks url: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// Top down approach - Must visit
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        
        vector<vector<int>> dp(n+1, vector<int>(k+1,1e9));
        return dfs(n, k, dp);
    }
    
    int dfs(int n, int k, vector<vector<int>>& dp)
    {
        int ans = 1e9;
        if(k==0 || k==1) return k;
        if(n==1) return k;
        if(dp[n][k]!=1e9) return dp[n][k];
        for(int i=1;i<=k;i++)
        {
            int break1 = dfs(n-1, i-1, dp);
            int not_break = dfs(n, k-i, dp);
            
            int temp = 1 + max(break1, not_break);
            ans = min(temp, ans);
        }
        return dp[n][k] = ans;
       //return dp[n][k] = min(1 + max(dfs(n-1, k-1, dp, f), dfs(n, f-k, dp, f)), dp[n][k]);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
