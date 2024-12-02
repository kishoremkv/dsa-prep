// codingninjas url - https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM
// TC - O(logN)
#include <bits/stdc++.h>
int NthRoot(int n, int m) {
  // Write your code here.

  int l = 1, r = sqrt(m);

  while(l <= r)
  {
    int mid = (r - l)/2 + l;

    long cur_val = mid;

    for(int i=0; i<n-1 ;i++)
    {
      cur_val*=mid;
      if(cur_val > m) break;
    }
    // cout<<cur_val<<" "<<mid<<endl;

    if(cur_val == m)
    {
      return mid;
    }
    else
    {
      if (cur_val > m) {
        r = mid - 1;
      } else
      {
        l = mid + 1;
      }
    }
  }

  return -1;
}
