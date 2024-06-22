// leetcodeUrl - https://leetcode.com/problems/search-a-2d-matrix/
// Optimal solution - Time complexity - O(Log(N*M)) - Space - O(N)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size(), ind = 0;
        int l = 0, r = m*n -1;

        while(l <= r)
        {
            int mid = l + (r-l)/2;

            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target) return true;
            if(matrix[row][col] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
