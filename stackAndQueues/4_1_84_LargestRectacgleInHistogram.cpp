// leetcode url - https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller(heights.size(), heights.size());
        vector<int> prevSmaller(heights.size(), -1);
        stack<int> s;
        for(int i=0; i<heights.size();i++)
        {
            while(!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }
            if(!s.empty()) 
            {
                prevSmaller[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!s.empty() && heights[i] <= heights[s.top()])
            {
                s.pop();
            }

            if(!s.empty())
            {
                nextSmaller[i] = s.top();
            }
            s.push(i);
        }
        int res = 0;
        for(int i=0;i<heights.size();i++)
        {
            cout<<prevSmaller[i]<<" "<<nextSmaller[i]<<endl;
            res = max(res, (nextSmaller[i] - prevSmaller[i] - 1) * heights[i]);
        }
        return res;
    }
};
