//https://leetcode.com/problems/copy-list-with-random-pointer/

//TC:O(n)   //SC:O(n)   //n is no. of nodes in LL
Node* copyRandomList(Node* head) {
        Node *ori=head;
        unordered_map<Node*,Node*> cmp;
        while(head!=NULL)
        {
            Node *p=new Node(head->val);
            cmp[head]=p;
            head=head->next;
        }
        
        head=ori;
        Node *dhead;
        while(head!=NULL)
        {
            dhead=cmp[head];
            dhead->random=cmp[head->random];
            dhead->next=cmp[head->next];
            head=head->next;
        }
        return cmp[ori];
    }

//TC:O(n)   //SC:O(1)   //n is no. of nodes in LL
Node* copyRandomList(Node* head) {
        Node *ori=head,*dhead,*ans;

        //Step1
        while(head!=NULL)
        {
            Node *p=new Node(head->val);
            p->next=head->next;
            head->next=p;
            head=p->next;
        }
        
        //step2
        head=ori;       
        while(head!=NULL)
        {
            dhead=head->next;
            if(head->random!=NULL)
            {
                dhead->random=head->random->next;
            }
            head=head->next->next;
        }
        
        //step3
        head=ori;
        if(ori!=NULL)
            ans=ori->next;
        else
            ans=NULL;
        while(head!=NULL)
        {
            dhead=head->next;
            head->next=dhead->next;
            if(dhead->next!=NULL)
                dhead->next=dhead->next->next;
            head=head->next;
        }
        return ans;
    }