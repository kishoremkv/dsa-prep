// leetcode url: https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        // reverse
        int n = s.size();
        reverse(s.begin(), s.end());
        int i = 0, j = 0, cur_ind = 0;
        while(i<n)
        {
            
            if(s[i] != ' ')
            {
                j = i;
                while(j<n && s[j]!=' ') s[cur_ind++] = s[j++];
                reverse(s.begin() + (cur_ind - (j-i)), s.begin() + cur_ind);
                
                s[cur_ind++] = ' ';
                i = j;
            }
            i++;
           
        }
        if(s[cur_ind-1] == ' ') cur_ind--;
        return s.substr(0, cur_ind);
    }
};
