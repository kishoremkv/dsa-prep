// leetcode url - https://leetcode.com/problems/kth-largest-element-in-an-array/
// Time Complexity - O(N*log(N))
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p(nums.begin(), nums.end());

        int res = 0;
        while(k--)
        {
            res = p.top();
            p.pop();
        }
        return res;
    }
};
