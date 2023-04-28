class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto x: prerequisites)
        {
          adj[x[1]].push_back(x[0]);
        }

        vector<int> indegrees(numCourses, 0);

        for(int i=0;i<numCourses;i++)
        for(auto x: adj[i])
        {
            indegrees[x]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
          if(indegrees[i]==0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty())
        {
          int node = q.front();
          q.pop();
          topo.push_back(node);
          for(auto x: adj[node])
          {
            indegrees[x]--;
            if(indegrees[x]==0) q.push(x);
          }

        }
        return (topo.size()==numCourses);
    }
};
