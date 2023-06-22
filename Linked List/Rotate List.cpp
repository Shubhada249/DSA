//https://leetcode.com/problems/rotate-list/

//TC:O(n)   //SC:O(1)   //n is no. of nodes in LL
ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ori=head;
        
        if(head==NULL)
            return head;
        
        //count nodes
        int cnt=1;
        while(head->next!=NULL)
        {
            cnt++;
            head=head->next;
        }
        
        if(k%cnt==0)
            return ori;
        else
        {
            head->next=ori;
            k=k%cnt;
            int f=cnt-k;
            ListNode* p=ori;
            while(f>1)
            {
                f--;
                p=p->next;
            }
            head=p->next;
            p->next=NULL;
            return head;
        }
    }