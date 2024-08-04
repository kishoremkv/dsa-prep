// leetcode url - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
// Time Complexity - O(N) 
// Space Complexity - O(1)
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size();
        int ones = 0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]) ones++;
        }

        if(!ones) return 0;

        int i = 0, j = ones - 1, res = INT_MAX;

        int cur_ones = 0;
        for(int k = i; k < j; k++) if(nums[k]) cur_ones++;

        for(int k = 0, n = nums.size(); k<nums.size(); k++)
        {
            if(nums[(k + ones - 1) % n]) cur_ones++;

            res = min(res, ones - cur_ones);

            if(nums[k]) cur_ones--;
        }
        return res;

    }
};
