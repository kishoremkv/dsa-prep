//leetcode url: https://leetcode.com/problems/minimum-path-sum/description/ 
// Bottom Up approach

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),INT_MAX));
        int n = grid.size(), m = grid[0].size();
        for(int i=n-1; i>=0;i--)
        {
            for(int j=m-1; j>=0;j--)
            {
                int cur_min = INT_MAX;
                if(i+1 < n) cur_min = min(cur_min, grid[i+1][j]);
                if(j+1 < m) cur_min = min(cur_min, grid[i][j+1]);

                if(cur_min != INT_MAX)
                    grid[i][j] = grid[i][j] + cur_min;
            }
        }

        return grid[0][0];

        // return dfs(0, 0, dp, grid);
    }

    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==grid.size() || j == grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j == grid[0].size()-1) return grid[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j]  = grid[i][j] + min(dfs(i+1, j, dp, grid), dfs(i, j+1, dp, grid));
    }
};
