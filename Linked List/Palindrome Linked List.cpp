//https://leetcode.com/problems/palindrome-linked-list/

//TC:O(n)   //SC:O(1)
bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        //count no. of nodes
        int total=0;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            total++;
            cur=cur->next;
        }
        
        //
        int start;
        if(total%2==0)
            start=(total/2);
        else
            start=(total/2)+1;
        
        //reverse ll
        int a=1;
        ListNode* lnode=head;
        while(a!=start)
        {
            lnode=lnode->next;
            a++;
        }
        
        ListNode* prev=lnode->next;
        cur=prev->next;
        while(cur!=NULL)
        {
            prev->next=cur->next;
            cur->next=lnode->next;
            lnode->next=cur;
            cur=prev->next;
        }
        
            cur=lnode->next;
        
        while(cur!=NULL)
        {
            if(head->val!=cur->val)
                return false;
            head=head->next;
            cur=cur->next;
        }
        return true;
    }