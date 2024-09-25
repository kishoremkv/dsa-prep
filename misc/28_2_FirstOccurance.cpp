// leetcode url - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1401414188/

class Solution {
public:
    int strStr(string hay, string needle) {
        vector<int> lps(needle.size());

        for(int i=1, len = 0; i<needle.size(); )
        {
            if(needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }
            else if(len)
            {
                len = lps[len - 1];
            }
            else lps[i++] = 0;

        }

        for(auto x:lps)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i=0, j=0; i<hay.size() && j<needle.size();)
        {
            if(needle[j] == hay[i])
            {
                cout<<i<<" "<<j<<endl;
                j++;i++;
            }
            else{
                if(!j) i++;
                j = lps[max(j-1, 0)];
            }
            if(j==needle.size()) return i-needle.size();
        }
        return -1;
    }
};
