// leetcode url: https://leetcode.com/problems/longest-palindromic-substring/
// Optimized Approach
// Time Complexity: O(n^2) 
// Space Complexity: O(1)
class Solution {
public:
    string ans = "";
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            expand_center(i, i, s);
            expand_center(i, i+1, s);
        }

        return ans;
    }

    void expand_center(int left, int right, string &s)
    {
        int n = s.size();
        while(left >=0 && right < n)
        {
            if(s[left] != s[right]) break;
            left--; right++;
        }
        if(ans.size() < right - left - 1)
        {
            ans = s.substr(left + 1, right-left-1);
        }
    }
};
