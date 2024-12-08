// leetode url - https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        /*
        // 1, 1, 2, 3, 3, 4, 4, 8, 8
        // 0. 1. 2  3. 4. 5. 6. 7. 8
            l = 0, r = 8, mid = 4
            l = 0, r = 3, mid = 1
            l = 1, r = 3, mid = 2
            l = 2, r = 3, mid = 2

            1 1 2
            0 1 2

            l = 0, r = 2, mid = 1
            l = 1, r = 2, mid = 1


        */
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size() -1] != nums[nums.size() -2]) return nums[nums.size() -1] ;
        while(l < r)
        {
            int mid = (r - l)/2 + l;

            if(mid > 0 && nums[mid] == nums[mid-1])
            {
                if(((mid-1 - l) % 2 == 0))
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 2;
                }
            }
            else if(mid < nums.size() -1 && nums[mid] == nums[mid+1])
            {
                if((r - (mid+1))%2 == 0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 2;
                }
            }
            else
            {
                return nums[mid];
            }
        }

        return nums[l];
    }
};
