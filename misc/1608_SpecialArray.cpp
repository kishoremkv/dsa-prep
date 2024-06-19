// leetcodeUrl - https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {


        vector<int> v(nums.size()+1, 0);

        for(auto x:nums)
        {
            v[min(x, (int)nums.size())]++;
        }

        for(int i=v.size()-2;i>=0;i--)
        {
            v[i] += v[i+1];
        }

        for(int i=0;i<v.size();i++)
        {
            if(v[i] == i) return i;
        }
        return -1;

      
    }
};
