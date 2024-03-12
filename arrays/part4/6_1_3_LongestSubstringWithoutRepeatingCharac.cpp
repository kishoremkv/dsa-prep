//leetcode url: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        int i=0, j=0, res=1;
        res = min((int)s.size(), res);
        unordered_map<int, int> um;

        while(j<s.size())
        {

            while(um[s[j]] == 1 && i!=j)
            {
                um[s[i++]]--;
            }
            res = max(res, j-i+1);
            um[s[j++]]++;
        }
        return res;
    }
};
