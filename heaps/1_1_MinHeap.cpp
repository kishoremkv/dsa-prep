// Code 360 - https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int> > heap;
    vector<int> res;

    for(auto x: q)
    {
        if(x[0] == 0)
        {
            heap.push(x[1]);
        }
        else
        {
            res.push_back(heap.top());
            heap.pop();
        }
    }
    return res;
}
