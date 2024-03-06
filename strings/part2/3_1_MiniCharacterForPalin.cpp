// interviewbit url: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
// Using LPS array 

int kmp_lps(string A)
{
    vector<int> lps(A.size(),0);
    
    int len = 0, i = 1;
    
    while(i<A.size())
    {
        if(A[i] == A[len])
        {
            lps[i] = len+1;
            i++;len++;
        }
        else
        {
            if(len == 0)
            {
                i++;
            }
            else
            {
                len = lps[len-1];
            }
        }
    }
    return lps[A.size()-1];
}
int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    B = A+"#"+B;
    return A.size() - kmp_lps(B);
    
    
}
