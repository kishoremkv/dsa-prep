// leetcode url - https://leetcode.com/problems/kth-largest-element-in-an-array/
// using quick sort 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r= nums.size()-1;

        while(1)
        {
            int ind = pivotElement(nums, l, r);

            if(ind == k-1)
            {
                return nums[ind];
            }
            if(ind > k-1)
            {
                r = ind -1;
            }
            else l = ind + 1;
        }

        return -1;
    }

    int pivotElement(vector<int>& nums, int l, int r)
    {
        int pivot = l;

        l++;

        while(l <= r)
        {
            if( nums[l] < nums[pivot] && nums[r] > nums[pivot] )
            {
                swap(nums[l], nums[r]);
                l++; r--;
            }

            if(nums[l] >= nums[pivot]) l++;
            if(nums[r] <= nums[pivot]) r--;
        }
        swap(nums[pivot], nums[r]);
        return r;
    }
};
