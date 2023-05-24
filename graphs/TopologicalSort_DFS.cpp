	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   vector<int> res;
	   vector<bool> visited(V, false);
	   stack<int> s;
	   for(int i=0;i<V;i++)
	   {
	       if(!visited[i])
	       {
	           dfs(i, adj, s, visited);
	       }
	   }
       while(!s.empty())
       {
           res.push_back(s.top());
           s.pop();
           
       }
       return res;
	}
	
	void dfs(int i, vector<int> adj[], stack<int> &s, vector<bool>& visited )
	{
	    for(auto x:adj[i])
	    {
	        if(!visited[x])
	        {
	            dfs(x, adj, s, visited);
	        }
	    }
	    visited[i] = 1;
	    s.push(i);
	}
