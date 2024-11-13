// spoj url - https://www.spoj.com/problems/AGGRCOW/
// Tc - O(N*logN)

#include <bits/stdc++.h>
    #include <iostream>
    using namespace std;

    // 1
    // 5 3
    // 1
    // 2
    // 8
    // 4
    // 9

    // 1 2 4 8 9 
    // N > 1 , C > 1 AND C <= N

    // 1 2 3 4 5 6 7 8 9 
    // s s 0 s 0 0 0 s 0
    // c  


    bool can_we_make(vector<int> &v, int val, int c)
    {
        c--;
        int ind = 0;
        while(c--)
        {
            int i;
            for(i = ind; i < v.size() && v[i]-v[ind] < val; i++)
            {

            }
            ind = i;
            if(ind == v.size()) break;
        }
        // cout<<"hello"<<endl;
        return c == -1;
    }


    int main()
    {
        int t;
        cin>>t;

        while(t--)
        {
            int n, c;
            cin>>n>>c;

            vector<int> v;
            for(int i=0; i<n; i++)
            {
                int x;
                cin>>x;
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            int l = 1, r = v.back() - v[0];
            while( l <= r)
            {
                int mid = l + (r-l)/2;
                if(can_we_make(v, mid, c))
                {
                    l = mid + 1;
                }
                else r = mid - 1; 
            }
            cout<<r<<endl;
            // cout<<"hello 2"<<endl;

        }
        return 0;
    }

