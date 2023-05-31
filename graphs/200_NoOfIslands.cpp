// Leetcode URL - https://leetcode.com/problems/number-of-islands/description/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis (n, vector<bool>(m, false));

        int res = 0;
        for(int i=0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, n, m, vis, grid);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(int i, int j, int n, int m, vector<vector<bool>>& vis, 
    vector<vector<char>>& grid)
    {
        vector<vector<int>> dir {{0, 1}, {1,0}, {0,-1}, {-1, 0}};

        vis[i][j] = 1;

        for(int k=0;k<4;k++)
        {
            int t = i+dir[k][0], p = j+dir[k][1];
            if(t<0 || p<0 || t>=n || p>=m) continue;
            if(!vis[t][p] && grid[t][p] == '1')
            {
                // cout<<t<<" "<<p<<endl;
                dfs(t, p, n, m, vis, grid);
            }
        }
    }
};
