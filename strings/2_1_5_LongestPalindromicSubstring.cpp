// leetcode url: https://leetcode.com/problems/longest-palindromic-substring/
// Time Complexity: O(n^2) 
// Space Complexity: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        // how to compute the is_palin to o(1)?

        vector<vector<int>> palin(s.size(), vector<int>(s.size(), 0));

        int n = s.size(), k=0, i=0,j=0;
        int res = 0;
        string str;

        while(k<n)
        {
            while(i<n && j<n)
            {
                if(i==j)
                {
                    palin[i][j] = 1;
                }
                else if(s[i] == s[j])
                {
                    if(abs(i- j)!=1)
                    {
                        if(palin[i+1][j-1])
                        palin[i][j] = j-i+1;
                    }
                    else 
                        palin[i][j] = j-i+1;
                }
                if(palin[i][j] > res)
                {
                    res = palin[i][j];
                    str = s.substr(i, j-i+1);
                }
                i++;j++;
            }
            i = 0;
            j = k+1;
            k++;
        }


        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(palin[i][j])
        //         {
        //             if(j-i+1 > res)
        //             {
        //                 res = j-i+1;
        //                 str = s.substr(i, j-i+1);
        //             }
        //             res = max(res, j-i+1);
        //         }
        //     }
        // }

        return str;
    }
};
