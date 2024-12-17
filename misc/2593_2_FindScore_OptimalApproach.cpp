// leetcode url  - https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/submissions/1480690278/
// TC - O(N) SC - O(1)

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;

        for(int i = 0; i < nums.size(); i+=2)
        {
            int cur_start = i;

            while(i+1 != nums.size() && nums[i+1] < nums[i])
            {
                i++;
            }

            for(int ind = i; ind >= cur_start; ind-=2)
            {
                res+= nums[ind];
            }
        }

        return res;
    }
};
