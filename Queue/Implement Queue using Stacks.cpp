//https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val=st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val=st2.top();
        return val;
    }
    
    bool empty() {
        if(st1.empty() && st2.empty())
            return true;
        return false;
    }
};
