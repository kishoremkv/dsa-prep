// Leetcode URL - https://leetcode.com/problems/longest-common-prefix/
// BruteForce Solution - Time Complexity - O(N^2) - Can be optimized using Trie

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool found = true;
        int i=1;
        while(found)
        {
            if(strs[0].size() <i) 
            {
                found = false;
                break;
            }
            string str = strs[0].substr(0, i);


            for(auto x: strs)
            {
                if(x.size() >=i)
                {
                    if(str != x.substr(0,i))
                    {
                        found = false;
                        i--;
                        break;
                    }
                }
                else
                {
                    found = false;
                    i--;
                    break;
                }
            }
            if(found)
            i++;
        }
        return strs[0].substr(0,i);
    }
};
