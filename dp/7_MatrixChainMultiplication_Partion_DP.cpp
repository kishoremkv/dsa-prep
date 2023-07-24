//geeksforgeeks url: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
public:

    int f(int i, int j, int arr[], int N, vector<vector<int>>& dp)
    {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k<j; k++)
        {
            int steps = arr[i-1]*arr[k]*arr[j] + f(i, k, arr, N, dp) + 
            f(k+1, j, arr, N, dp);
            mini = min(steps, mini);
        }
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return f(1, N-1, arr, N, dp);
    }
};
