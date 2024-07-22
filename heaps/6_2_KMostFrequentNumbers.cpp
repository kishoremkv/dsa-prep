// leetcode url - https://leetcode.com/problems/top-k-frequent-elements
// Time complexity - O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for(auto x:nums)
        {
            um[x]++;
        }

        vector<vector<int>> v( nums.size() + 1);
        vector<int> res;
        
        for(auto x: um)
        {
           v[x.second].push_back(x.first);
        }

        for(int i = v.size() -1; i>=0;i--)
        {
            if(k == 0) break;
            if(v[i].size() < k)
            {
                for(auto x: v[i])
                {
                    res.push_back(x);
                }
                k = k - v[i].size();
            }
            else
            {
                for(int j=0;k>0 && j<v[i].size();j++, k--)
                {
                    res.push_back(v[i][j]);
                }
            }
        }


        // priority_queue<pair<int, int> > pq;
        // for(auto x: um)
        // {
        //     pq.push({x.second, x.first});
        //     if(pq.size() > um.size() - k)
        //     {
        //         res.push_back(pq.top().second);
        //         pq.pop();
        //     }
        // }
        return res;
    }
};
