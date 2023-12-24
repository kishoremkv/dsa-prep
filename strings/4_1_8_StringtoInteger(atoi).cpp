//leetcode url: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        bool started = false;
        bool neg = false; long long res = 0;
        int i = 0;

        while(i<s.size())
        {
            // if(neg && res <= INT_MIN) return INT_MIN;
            if(res >= INT_MAX || res >= long(INT_MAX) + 1)
            {
                if(neg && res >= long(INT_MAX)+1) return INT_MIN;
                else return INT_MAX;
            } 
            if((s[i] == '-' || s[i] == '+') && !started) 
            {
                if(s[i] == '-')
                neg = true;
                started = true;
                i++;continue;
            }
            if(s[i] >='0' && s[i] <='9')
            {
                started = true;
                res = res*10 + s[i] - '0';
            }

            if(started)
            {
                if(!(s[i]>='0' && s[i]<='9'))
                {
                    break;
                }
            }
            else
            {
                if(s[i] != ' ' && s[i] != ' '  && !(s[i]>='0' && s[i]<='9'))
                    break;
            }
            
            i++;
        }
        res = neg? -1*res : res;
        if(res <= INT_MIN) return INT_MIN;
        if(res >= INT_MAX) return INT_MAX;
        return res;
    }
};
