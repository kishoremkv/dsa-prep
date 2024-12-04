// geeksforgeeks url - https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix
// TimeComplexity - O(logN) * O(MlogN)

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        // [3], [5], [8]
        
        int low = INT_MAX, high = INT_MIN;
        
        for(int i=0; i<mat.size(); i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][mat[0].size() - 1]);
        }
        
        
        int req = (mat.size() * mat[0].size()) / 2;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(black_box(mat, mid) <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return low;
    }
    
    int black_box(vector<vector<int>> &mat, int val)
    {
        int count = 0;
        
        for(auto x: mat)
        {
            int ind = upper_bound(x.begin(), x.end(), val) - x.begin();
            
            count += ind;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
