//https://leetcode.com/problems/remove-linked-list-elements/

//TC:O(n)   //SC:O(1)
ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev=head,*cur=head;
        while(cur!=NULL)
        {
            if(cur->val==val)
            {
                if(cur==prev)
                {
                    head=prev->next;
                    cur=head;
                    prev=head;
                    continue;
                }
                else
                {
                    prev->next=cur->next;
                    cur=prev->next;
                    continue;
                }
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }