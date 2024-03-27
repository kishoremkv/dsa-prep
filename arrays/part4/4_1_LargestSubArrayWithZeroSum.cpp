// geeksforgeeks url: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> um;
        um[0] = -1;
        
        int cur_sum = 0, res = 0;
        
        for(int i=0;i<n;i++)
        {
            cur_sum += A[i];
            
            
            if(um.find(cur_sum)!=um.end())
            {
                res = max(res, i-um[cur_sum]);
                // um[A[i]] = i;
            }
            else
            {
                um[cur_sum] = i;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
