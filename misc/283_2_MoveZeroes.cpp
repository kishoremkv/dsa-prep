// leetcode-url: https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0, e = 1;
        while(s < nums.size() && nums[s] != 0 ) s++;
        e = s+1;
        while(e< nums.size())
        {
            if(nums[e]!=0)
            {
                nums[s] = nums[e];
                nums[e] = 0;
                s++; e++;
            }
            else e++;

        }
    }
};
