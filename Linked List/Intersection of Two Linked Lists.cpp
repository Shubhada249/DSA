//https://leetcode.com/problems/intersection-of-two-linked-lists/
//TC:O(m*n)     //SC:O(1)
......

//TC:O(m+n)     //SC:O(m)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur=headA;
        unordered_set<ListNode *> st;
        while(cur!=NULL)
        {
            st.insert(cur);
            cur=cur->next;
        }
        
        cur=headB;
        while(cur!=NULL)
        {
            if(st.find(cur)!=st.end())
                return cur;
            cur=cur->next;
        }
        return NULL;
    }

//TC:O(m+n)     //SC:O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *d1=headA,*d2=headB;
        while(d1!=NULL && d2!=NULL)
        {
            d1=d1->next;
            d2=d2->next;
        }
        if(d1==NULL)
            d1=headB;
        if(d2==NULL)
            d2=headA;
        while(d1!=NULL && d2!=NULL)
        {
            d1=d1->next;
            d2=d2->next;
        }
        if(d1==NULL)
            d1=headB;
        if(d2==NULL)
            d2=headA;
        while(d1!=d2 && d1!=NULL && d2!=NULL)
        {
            d1=d1->next;
            d2=d2->next;
        }
        if(d1==d2)
            return d1;
        return NULL;
    }