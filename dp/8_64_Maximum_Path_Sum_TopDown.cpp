//leetcode url: https://leetcode.com/problems/minimum-path-sum/description/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),INT_MAX));

        return dfs(0, 0, dp, grid);
    }

    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(i==grid.size() || j == grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j == grid[0].size()-1) return grid[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j]  = grid[i][j] + min(dfs(i+1, j, dp, grid), dfs(i, j+1, dp, grid));
    }
};
