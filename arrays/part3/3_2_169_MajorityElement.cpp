// leetcode url: https://leetcode.com/problems/majority-element/
// using Moor's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ele = nums[0],  count = 0;

        for(auto x: nums)
        {
            if(count == 0)
            {
                ele = x;
            }
            if(ele == x)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ele;
    }
};
