	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    vector<int> indegrees(V, 0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int j=0;j<adj[i].size();j++)
	        {
	            indegrees[adj[i][j]]++;
	        }
	    }
	    
	    vector<int> res;
	    while(findZero(indegrees)!=-1)
	    {
	        int x = findZero(indegrees);
	        for(int i=0;i<adj[x].size();i++)
	        {
	            indegrees[adj[x][i]]--;
	        }
	        indegrees[x] = -1;
	        res.push_back(x);
	    }
	    return res;
	    
	    
	}
	
	int findZero(vector<int> &ind)
	{
	    for(int i=0;i<ind.size();i++)
	    {
	        if(ind[i]==0)return i;
	    }
	    return -1;
	}
