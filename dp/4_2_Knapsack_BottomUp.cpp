 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=W;j++)
           {
                if(wt[i-1]<=j)
                {
                    dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
           }
        //   cout<<endl;
       }
       return dp[n][W];
    //   if(W<wt[0])
    //   return dfs(0, 1, dp, wt, val, W);
    //   else
    //   return max(val[0] + dfs(wt[0], 1, dp, wt, val, W),
    //   dfs(0, 1, dp, wt, val, W));
    }
