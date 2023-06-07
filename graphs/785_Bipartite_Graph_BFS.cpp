// leetcode link: https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;

        int n = graph.size();
        vector<int> col(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(col[i] == -1)
            {
                q.push(i);
                col[i] = 0;
            }

            while(!q.empty())
            {
                int x= q.front();
                q.pop();
                for(auto g: graph[x])
                {
                    if(col[g]== -1)
                    {
                        col[g] = !col[x];
                        q.push(g);
                    }
                    else if(col[g] == col[x]) return false;

                }
            }
        }
        return true;



    }
};
