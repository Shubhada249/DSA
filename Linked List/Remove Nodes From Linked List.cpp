//https://leetcode.com/problems/remove-nodes-from-linked-list/

//TC:O(n)   //SC:O(n)
ListNode* reversell(ListNode* head) 
    {
        ListNode *c=head,*p=NULL,*n=head->next;
        while(c)
        {
            c->next=p;
            p=c;
            c=n;
            if(c)
                n=c->next;
        }
        return p;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reversell(head);
        stack<int> st;
        st.push(head->val);
        ListNode *c=head->next,*p=head;
        while(c)
        {
            if(st.top()>(c->val))
            {
                p->next=c->next;
                c=p->next;
            }
            else
            {
                st.push(c->val);
                p=c;
                c=p->next;
            }
        }
        head=reversell(head);
        return head;
    }
//TC:O(n)   //SC:O(n)
ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL)
            return head;
        head->next=removeNodes(head->next);
        if(head->val >= head->next->val)
            return head;
        else
            return head->next;
    }

//TC:O(n)   //SC:O(1)
ListNode* reversell(ListNode* head) 
    {
        ListNode *c=head,*p=NULL,*n=head->next;
        while(c)
        {
            c->next=p;
            p=c;
            c=n;
            if(c)
                n=c->next;
        }
        return p;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reversell(head);
        ListNode *c=head->next,*p=head;
        //int maxi=p->val;
        while(c)
        {
            if((p->val)>(c->val))
            {
                p->next=c->next;
                c=p->next;
            }
            else
            {
                //maxi=c->val;
                p=c;
                c=p->next;
            }
        }
        head=reversell(head);
        return head;
    }