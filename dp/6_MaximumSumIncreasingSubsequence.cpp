// geeksforgeeks: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> res(arr, arr+n);
	    for(int i=1;i<n;i++)
	    {
	        int t = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i] > arr[j])
	            {
	                t = max(res[j], t);
	            }
	        }
	        res[i] = t + arr[i];
	    }
	    
	    return *max_element(res.begin(), res.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
