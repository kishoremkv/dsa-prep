// leetcode url - https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 0, 1, 2
        // 100000, 1, 5, 3 ,2
        //                  
        // 100000, 1, 1, 1,

        // [0, 0, 0, 0] -> bool with nums as size
        // [1, 1, 0, 1]

        // 3, 2, 1, 4

        // [0, 0, 1, 0]
        // [0, 1, 1, 0]
        // [1, 1, 1, 1]
        // 


        vector<bool> v(nums.size(), 0);

        for(int  i=0;i<nums.size();i++)
        {
            if(nums[i] > 0 && nums[i] <= nums.size())
            {
                v[nums[i]-1] = true;
            }
        }

        int res = 0;

        for(int i=0;i<v.size();i++)
        {
            if(v[i] == false)
            {
                return i+1;
            }
        }

        return nums.size() + 1;
    }
};
