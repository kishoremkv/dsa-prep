//leetcode url: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // hello world
        unordered_set<int> um;
        for(int i=0;i<nums.size();i++)
        {
            um.insert(nums[i]);
        }
        int res = 0;
        for(auto x:nums)
        {
            int i = x,j=x;
            while(um.find(i)!=um.end()){ if(i!=j)um.erase(i);i--;}
            while(um.find(j)!=um.end()){um.erase(j);j++;}

            res = max(j-i-1, res);
        }
        return res;
    }
};
