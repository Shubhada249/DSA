//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

//TC:O(n)   //SC:O(1)
Node* fun(Node* q)
    {
        while(q->next!=NULL)
            q=q->next;
        return q;
    }
    Node* flatten(Node* head) {
        Node* cur=head;
        while(cur!=NULL)
        {
            if(cur->child==NULL)
                cur=cur->next;
            else
            {
                Node* p=cur->next;
                cur->next=cur->child;
                cur->child=NULL;
                cur->next->prev=cur;
                Node* lnode=fun(cur->next);
                lnode->next=p;
                if(p!=NULL)
                    p->prev=lnode;
                cur=cur->next;
            }
        }
        return head;
    }