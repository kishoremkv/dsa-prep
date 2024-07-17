// interviewbit url - https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) { 
    
    set< pair<int, int> > us;
    sort(A.begin(), A.end(), greater<int>() );
    sort(B.begin(), B.end(), greater<int>() );
    vector<int> res;
    priority_queue< pair<int, pair<int, int> > > pq;
    pq.push({A[0] + B[0], {0, 0} });
    
    while(C--)
    {
        auto x = pq.top();
        pq.pop();
        
        while(us.find(x.second) != us.end())
        {
            if(!pq.empty())
            x = pq.top();
            pq.pop();
            
        }
        us.insert({x.second.first, x.second.second});
        pq.push({A[x.second.first] + B[x.second.second + 1], {x.second.first, x.second.second + 1}});
        pq.push({A[x.second.first + 1] + B[x.second.second], {x.second.first + 1, x.second.second}});
        res.push_back(x.first);
    }
    
    return res;
}


