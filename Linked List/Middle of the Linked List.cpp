//https://leetcode.com/problems/middle-of-the-linked-list/

//TC:O(n)   //SC:O(1)
ListNode* middleNode(ListNode* head) {
        ListNode *s=head,*f=head;
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }