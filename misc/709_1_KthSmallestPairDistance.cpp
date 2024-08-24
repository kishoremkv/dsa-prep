// leetcode url - https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
// using bucket sort
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> diff;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j = i+1; j<nums.size();j++)
            {
                diff.push_back(nums[j]-nums[i]);
            }
        }
        vector<int> bucket(nums.back()+1, 0);

        for(auto x: diff)
        {
            bucket[x]++;
        }

        for(int i=0;i<bucket.size();i++)
        {
            k = k - bucket[i];
            if(k<=0) return i;
        }
        return -1;
    }
};
