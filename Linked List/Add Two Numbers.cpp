//https://leetcode.com/problems/add-two-numbers/

//TC:O(m)   //SC:O(m)   //m is length of larger of two LL
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*prev;
        int carry=0;
        bool ch=false;
        while(l1!=NULL && l2!=NULL)
        {
            
            int sum=(l1->val) + (l2->val)+carry;
            carry=sum/10;
            sum=sum%10;                
            ListNode* cur=new ListNode(sum);
            if(ch==false)
            {
                ch=true;
                head=cur;
                prev=cur;
            }
            else
            {
                prev->next=cur;
                prev=cur;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                int sum=(l1->val)+carry;
                carry=sum/10;
                sum=sum%10;                
                ListNode* cur=new ListNode(sum);
                prev->next=cur;
                prev=cur;
                l1=l1->next;
            }
            if(carry!=0)
            {
                ListNode* cur=new ListNode(carry);
                prev->next=cur;
            }
        }
        else
        {
            while(l2!=NULL)
            {
                int sum=(l2->val)+carry;
                carry=sum/10;
                sum=sum%10;                
                ListNode* cur=new ListNode(sum);
                prev->next=cur;
                prev=cur;
                l2=l2->next;
            }
            if(carry!=0)
            {
                ListNode* cur=new ListNode(carry);
                prev->next=cur;
            }
        }
        return head;
    }

//TC:O(m)   //SC:O(1)   //m is length of larger of two LL
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*prev;
        int carry=0;
        bool ch=false;
        while(l1!=NULL && l2!=NULL)
        {
            
            int sum=(l1->val) + (l2->val)+carry;
            carry=sum/10;
            sum=sum%10;                
            //ListNode* cur=new ListNode(sum);
            l1->val=sum;
            if(ch==false)
            {
                ch=true;              
                head=l1;
                prev=l1;
            }
            else
            {
                prev->next=l1;
                prev=l1;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                int sum=(l1->val)+carry;
                carry=sum/10;
                sum=sum%10;                
                //ListNode* cur=new ListNode(sum);
                l1->val=sum;
                prev->next=l1;
                prev=l1;
                l1=l1->next;
            }
            if(carry!=0)
            {
                ListNode* cur=new ListNode(carry);
                prev->next=cur;
            }
        }
        else
        {
            while(l2!=NULL)
            {
                int sum=(l2->val)+carry;
                carry=sum/10;
                sum=sum%10;                
                //ListNode* cur=new ListNode(sum);
                l2->val=sum;
                prev->next=l2;
                prev=l2;
                l2=l2->next;
            }
            if(carry!=0)
            {
                ListNode* cur=new ListNode(carry);
                prev->next=cur;
            }
        }
        return head;
    }