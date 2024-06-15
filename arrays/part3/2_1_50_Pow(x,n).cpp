//leetcode url: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double cur_pow = 1, cur_val = 0;
        if(n < 0) x = 1/x;
        long num = labs(n);
        while(num)
        {
            if(num & 1)
            {
                cur_pow*=x;
            }
            num >>= 1;
            x = x * x;
            cout<<cur_pow<<endl;

        }
        return cur_pow;

    }
};
