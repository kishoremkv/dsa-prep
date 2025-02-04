// leetcode url - https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    StockSpanner() {
        // s.erase();
    }
    stack<pair<int, int>> s;
    int next(int price) {
        // find the no of stocks
        // price -> 
        // for all from backwards you check arr[i] <= price
        // {100, 1}, {85, 6}
        int count = 1;
        while(!s.empty() && s.top().first <= price)
        {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
