// leetcode url - https://leetcode.com/problems/find-median-from-data-stream/
// Time Complexity - O(N*log(N))
// Space Complexity - O(N)
class MedianFinder {
public:

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    MedianFinder() {
        maxi.empty(); mini.empty();
    }
    
    void addNum(int num) {

        if(maxi.empty() && mini.empty())
        {
            maxi.push(num);
        }
        else if(maxi.empty())
        {
            if(num > mini.top())
            {
                mini.push(num);
                maxi.push(mini.top());
                mini.pop();
            }
            else
            {
                maxi.push(num);
            }
        }
        else
        {
            if(num < maxi.top())
            {
                maxi.push(num);
                mini.push(maxi.top());
                maxi.pop();
            }
            else
            {
                mini.push(num);
            }
        }
        
        if(maxi.size() == mini.size())
        {
            if(num > mini.top() || num > maxi.top())
            {
                mini.push(num);
            }
            else 
            {
                maxi.push(num);
                mini.push(maxi.top());
                maxi.pop();
            }
        }
        else if(maxi.size() < mini.size())
        {
            if(num > mini.top())
            {
                mini.push(num);
                maxi.push(mini.top());
                mini.pop();
            }
            else
            {
                maxi.push(num);
            }
        }
        else
        {
            if(num < maxi.top())
            {
                maxi.push(num);
                mini.push(maxi.top());
                maxi.pop();
            }
            else
            {
                mini.push(num);
            }
        }
    }
    
    double findMedian() {
        if((maxi.size() + mini.size())%2)
        {
            return mini.top();
        }
        else
        {
            double res = (maxi.top() + mini.top());
            return res/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
