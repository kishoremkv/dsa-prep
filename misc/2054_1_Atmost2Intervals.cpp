// leetcode url - https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> v;

        for(auto x: events)
        {
            v.push_back({x[0], 1, x[2]});
            v.push_back({x[1]+1 , -1, x[2]});
        }

        sort(v.begin(), v.end());

        int max_seen = 0, max_val = 0;

        for(auto x: v)
        {
            if(x[1] == 1)
            {
                max_val = max(max_val, max_seen + x[2]);

            }
            else
            {
                max_seen = max(max_seen, x[2]);
            }
        }
        return max_val;
    }
};
