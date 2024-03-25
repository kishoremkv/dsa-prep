// interview bit url: https://www.interviewbit.com/problems/subarray-with-given-xor/
// Optimal solution using hash map

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> pre;
    
    int res = 0;
    int cur_xor = 0;
    pre.insert({0,1});
    for(int i=0;i<A.size();i++)
    {
        cur_xor = A[i] ^ cur_xor;
        if(pre.find(cur_xor^B)!=pre.end())
        {
            res+= pre[cur_xor^B];
        }
        pre[cur_xor]++;
    }
    for(auto x:pre)
    {
        // cout<<x.first<<" "<<x.second<<endl;
    }
    return res;
}
