//leetcode url: https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,int> um1, um2;
        for(auto x:s) um1[x]++;
        for(auto x:t) um2[x]++;

        for(auto x: um1)
        {
            if(um2[x.first] != x.second)
            return false;
        }
        return true;
    }
};
