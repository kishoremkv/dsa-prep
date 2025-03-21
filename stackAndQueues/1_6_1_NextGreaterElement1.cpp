// leetcode url - https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ng(nums2.size(), -1);

        for(int i = nums2.size()-1; i>=0; i--)
        {

            while(!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }

            if(!s.empty())
            {
                ng[i] = s.top();
            }
            s.push(nums2[i]);

        }

        unordered_map<int, int> um;
        for(int i=0;i<nums2.size();i++)
        {
            um.insert({nums2[i], ng[i]});
        }

        vector<int> ans(nums1.size());

        for(int i=0;i<nums1.size(); i++)
        {
            ans[i] = um[nums1[i]];
        }
        return ans;
    }
};
