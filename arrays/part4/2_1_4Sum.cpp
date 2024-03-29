// leetcode url: https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int> > res;

        unordered_map<long long, int> um;
        sort(nums.begin(), nums.end());
        um[nums[0]] = 1;
        
        if(nums.size()<4) return {};

        for(int i=1;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    long long s = (long long)target -(long long)nums[k]-(long long)nums[j]-(long long)nums[i];
                    if(um.find(s)!=um.end())
                    {
                        // while(um[target-nums[k]-nums[j]-nums[i]]--)
                        res.insert({nums[i], nums[j],nums[k],(int)s});
                    }
                }
            }
            um[nums[i]]++;
        }
        return vector(res.begin(), res.end());
    }
};
