// leetcode link: https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> color(graph.size(), -1);

        vector<bool> visited(graph.size(), false);

        for(int i=0; i < graph.size(); i++)
        {
            if(!visited[i])
            {
                if(!dfs(i, color, visited, graph, 0))
                return false;
            }
        }
        
        return true;
    }

    bool dfs(int ind, vector<bool>& color, vector<bool>& visited, 
    vector<vector<int>>& graph, bool cur_col)
    {
        visited[ind] = true;
        color[ind] = cur_col;

        for(auto x: graph[ind])
        {
            if(visited[x] && color[x] == cur_col)
                return false;
            if(!visited[x])
                if(!dfs(x, color, visited, graph, !cur_col))
                return false;
        }
        return true;
    }
};
