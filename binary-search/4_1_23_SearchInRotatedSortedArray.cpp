// leetcode url - https://leetcode.com/problems/search-in-rotated-sorted-array/

// TC - Log(N)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int mid = (r-l)/2 + l;

            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else 
            {
                r = mid;
            }
        }
        int rot_ind = l;

        l = 0, r = nums.size() - 1;

        while(l <=r)
        {
            int mid = (r - l)/2 + l;
            int rot_mid = (mid + rot_ind) %nums.size();

            if(nums[rot_mid] < target)
            {
                l = mid + 1;
            }
            else if(nums[rot_mid] > target)
            {
                r = mid - 1;
            }
            else
                return rot_mid;
        }

        return -1;
    }
};
