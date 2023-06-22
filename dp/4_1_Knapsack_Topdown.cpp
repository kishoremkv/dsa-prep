// geeksforgeeks link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       if(W<wt[0])
       return dfs(0, 1, dp, wt, val, W);
       else
       return max(val[0] + dfs(wt[0], 1, dp, wt, val, W),
       dfs(0, 1, dp, wt, val, W));
    }
    
    int dfs(int cur_wt, int ind, vector<vector<int>> &dp, int wt[], int val[], int W)
    {
        if(ind == dp.size()) return 0;
        if(dp[ind][cur_wt] !=-1)
        return dp[ind][cur_wt];
        
        if(cur_wt + wt[ind] > W)
        return dp[ind][cur_wt] = dfs(cur_wt, ind+1, dp, wt, val, W);
        
        else return dp[ind][cur_wt] =  max(val[ind] + dfs(cur_wt + wt[ind], ind+1, 
        dp, wt, val, W), dfs(cur_wt, ind+1, dp, wt, val, W));
        
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
