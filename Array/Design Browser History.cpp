//https://leetcode.com/problems/design-browser-history/


//using two stack
class BrowserHistory {
public:
    string cur;
    stack<string> history,future;
    BrowserHistory(string homepage) {
        cur=homepage;
    }
    
    void visit(string url) {        //TC:O(1)
        history.push(cur);
        cur=url;
        future=stack<string>();
    }
    
    string back(int steps) {        //TC:O(min(steps,size))
        while(!history.empty() && steps--)
        {
            future.push(cur);
            cur=history.top();
            history.pop();
        }
        return cur;
    }
    
    string forward(int steps) {     //TC:O(min(steps,size))
        while(!future.empty() && steps--)
        {
            history.push(cur);
            cur=future.top();
            future.pop();
        }
        return cur;
    }
};

//Using Doubly LL
class Node
{
    public:
    string val;
    Node *next,*prev;   
    Node(string str)
    {
        val=str;
        next=NULL;
        prev=NULL;
    }
};
class BrowserHistory {
public:
    Node *head,*cur;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
        cur=head;
    }
    
    void visit(string url) {        //TC:O(1)
        Node *v=new Node(url);
        cur->next=v;
        v->prev=cur;
        cur=v;
    }
    
    string back(int steps) {        //TC:O(min(steps,size))
        while(head!=cur && steps--)
        {
            cur=cur->prev;
        }
        return cur->val;
    }
    
    string forward(int steps) {     //TC:O(min(steps,size))
        while(cur->next!=NULL && steps--)
            cur=cur->next;
        return cur->val;
    }
};

//Using vector
class BrowserHistory {
public:
    vector<string> vec;
    int ptr=0,last=0;
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
    }
    
    void visit(string url) {        //TC:O(1)
        ptr++;
        if(ptr==vec.size())
            vec.push_back(url);
        else
            vec[ptr]=url;
        last=ptr;
    }
    
    string back(int steps) {        //TC:O(1)
        if(steps>ptr)
            steps=ptr;
        ptr=ptr-steps;
        return vec[ptr];
    }
    
    string forward(int steps) {     //TC:O(1)
        if(steps>last-ptr)
            steps=last-ptr;
        ptr=ptr+steps;
        return vec[ptr];
    }
};

