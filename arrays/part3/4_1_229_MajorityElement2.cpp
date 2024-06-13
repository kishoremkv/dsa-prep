// leetcodeUrl - https://leetcode.com/problems/majority-element-ii/
// Time Complexity - O(n) 
// Space Complexity - O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // find all the 

        int count2 = 0, ele2 = INT_MIN;
        int ele = INT_MIN,  count = 0;

        for(auto x: nums)
        {
            if(count == 0 && ele2 != x)
            {
                ele = x;
            }
            else if(ele !=x && count2 == 0) ele2 = x;
            if(ele == x)
            {
                count++;
            }
            else if(ele2 == x)
            {
                count2++;
            }
            else
            {
                count--;
                count2--;
            }
        }
        count = 0, count2 = 0;
        for(auto x: nums)
        {
            if(x == ele) count++;
            if(x == ele2) count2++;
        }
        vector<int> res;
        cout<<ele<<" "<<ele2<<endl;
        cout<<count<<" "<<count2<<endl;
        if(count > nums.size()/3) res.push_back(ele);
        if(count2 > nums.size()/3) res.push_back(ele2);
        return res;
    }
};
