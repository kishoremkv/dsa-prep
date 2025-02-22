// coding-ninja's url - https://www.naukri.com/code360/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION
// Time complexity - O(N)

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.

    vector<int> prev(a.size(), -1);
    vector<int> next(a.size(), n);
    vector<int> res(a.size(), INT_MIN);
    stack<int> mono;

    // go from left to right

    // previous smaller element
    for(int i=0;i<a.size();i++)
    {
        // if(!mono.empty() && a[mono.top()] < a[i]) prev[i] = mono.top();
        while(!mono.empty() && a[mono.top()] >= a[i])
        {
            mono.pop();
        }
        // if(!mono.empty()) prev[i] = mono.top();
        if(!mono.empty()) prev[i] = mono.top();

        mono.push(i);
        // mono.push(i);
        
    }

    mono = stack<int>();

    // next smaller element

    for(int i=n-1;i>=0;i--)
    {
        // if(!mono.empty() && a[mono.top()] < a[i]) next[i] = mono.top();
        while(!mono.empty() && a[mono.top()] >= a[i])
        {
            mono.pop();
        }
        if(!mono.empty()) next[i] = mono.top();
        mono.push(i);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<prev[i]<<" ";
    // }
    // cout<<endl;

    // for(int i=0;i<n;i++)
    // {
    //     cout<<next[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0;i<a.size();i++)
    {
        res[next[i] - prev[i] - 2] = max(res[next[i] - prev[i] - 2], a[i]); 
    }

    for(int i = n-2;i>=0;i--)
    {
        res[i] = max(res[i+1], res[i]);
    }
    return res;
    
}
