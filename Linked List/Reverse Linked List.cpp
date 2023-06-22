//https://leetcode.com/problems/reverse-linked-list/

//TC:O(n^2)   //SC:O(n)     //Recursive
ListNode* fun(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* cur=head,*lnode;
    while(cur->next->next!=NULL)
    {
        cur=cur->next;
    }
    lnode=cur->next;
    cur->next=NULL;
    head=fun(head);
    lnode->next=head;
    head=lnode;
    return head;
}
ListNode* reverseList(ListNode* head) {   
    return fun(head);
}

//TC:O(n)   //SC:O(1)       //Iterative
ListNode* reverseList(ListNode* head) {
        ListNode* prev=head,*lnode;
        while(prev!=NULL && prev->next!=NULL)
        {
            lnode=prev->next;
            prev->next=lnode->next;
            lnode->next=head;
            head=lnode;
        }
        return head;
    }

//TC:O(n)   //SC:O(n)       //Recursive
ListNode* fun(ListNode* prev,ListNode* head)
    {
        if(prev==NULL || prev->next==NULL)
            return head;
        ListNode *lnode;
        
        lnode=prev->next;
        prev->next=lnode->next;
        lnode->next=head;
        head=lnode;
        return fun(prev,head);
        
    }
    ListNode* reverseList(ListNode* head) {
        
        return fun(head,head);
    }