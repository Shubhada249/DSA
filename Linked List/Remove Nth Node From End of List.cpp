//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

//TC:O(n)   //SC:O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1=head,*p2=head,*prev;
        
        while(n--)
        {
            p2=p2->next;
        }
        if(p2==NULL)
        {
            head=p1->next;
            return head;
        }
        while(p2!=NULL)
        {
            prev=p1;
            p1=p1->next;
            p2=p2->next;
        }
        prev->next=p1->next;
        return head;
    }