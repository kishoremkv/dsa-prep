// leetcode url: https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string temp = "1";
        for(int i=2;i<=n;i++)
        {
            temp = say(temp);
        }
        return temp;
    }

    string say(string str)
    {
        string res=""; 
        char ch = str[0];
        int count = 1;

        for(int i=1;i<str.size();i++)
        {
            if(ch == str[i])
            {
                count++;
            }
            else
            {
                res.push_back((char)(count+'0'));
                res.push_back(ch);
                ch = str[i];
                count=1;
            }

        }
        res.push_back((char)(count+'0'));
        res.push_back(ch);
        return res;

    }
};
