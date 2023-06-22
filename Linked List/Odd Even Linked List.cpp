//https://leetcode.com/problems/odd-even-linked-list/

//TC:O(n)   //SC:O(1)
ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        
        ListNode* prev=head,*cur=prev->next,*al=head,*vl;
        while(al->next!=NULL)
        {
            al=al->next;
        }
        vl=al;
        while(cur!=al && prev!=al)
        {
            prev->next=prev->next->next;
            vl->next=cur;
            cur->next=NULL;
            vl=cur;
            prev=prev->next;
            cur=prev->next;
        }
        if(cur==al)
        {
            prev->next=prev->next->next;
            vl->next=cur;
            cur->next=NULL;
        }
        return head;
    }