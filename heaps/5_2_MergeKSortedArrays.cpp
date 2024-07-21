// coding ninjas url - https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTabValue=PROBLEM
// Time complexity - O(N*K*Log(K))
// Space complexity - O(K)

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 

    priority_queue< pair<int,pair<int, int> >, vector<pair<int,pair<int, int> > >, greater<pair<int,pair<int, int> > > > pq;

    for(int i=0; i < k ; i++)
    {
        pq.push({kArrays[i][0], {i, 0}});
    }

    vector<int> res;

    while(!pq.empty())
    {
        auto x = pq.top().second;
        res.push_back(pq.top().first);
        if(x.second != kArrays[x.first].size()-1)
        {
          pq.push({kArrays[x.first][x.second + 1], {x.first, x.second + 1}});
        }
        pq.pop();
    }

    return res;
}
