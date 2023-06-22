//https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // 2, 3, -2, 4
        int cur_min = nums[0], cur_max = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int x = nums[i];
            if(x < 0)
            {
                int temp_cur_max = cur_max;
                temp_cur_max = max(cur_min * x, x);
                cur_min = min(cur_max * x, x);
                cur_max = temp_cur_max;
            }
            else
            {
                cur_min = min(x, cur_min * x);
                cur_max = max(x, cur_max * x);
            }
            res = max(cur_max, res);

        }
        return res;
    }
};
