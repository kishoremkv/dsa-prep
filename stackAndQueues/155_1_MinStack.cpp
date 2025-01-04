class MinStack {
public:

    struct Node {
        int val;
        int min_val;
    };
    stack<Node*> s;
    MinStack() {
        s.empty();
        
    }
    //
    void push(int val) {
        Node *n = new Node();
        n->val = val;
        n->min_val = val;
        if(!s.empty())
        {
            Node *top = s.top();
            n->min_val = min(n->min_val, top->min_val);
        }
        s.push(n);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top()->val;
    }
    
    int getMin() {
        return s.top()->min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
