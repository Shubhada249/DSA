//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/



//TC:O(n)   //SC:O(n)
int pairSum(ListNode* head) {
        int cnt=0,n=0;
        stack<int> st;
        ListNode *prev;
        prev=head;
        while(prev!=NULL)
        {
            n++;
            prev=prev->next;
        }
        prev=head;
        while(cnt!=n/2)
        {
            st.push(prev->val);
            prev=prev->next;
            cnt++;
        }
        int ans=0;
        while(prev!=NULL)
        {
           ans=max(ans,st.top()+(prev->val));
            st.pop();
            prev=prev->next;
        }
        return ans;
    }

//TC:O(n)   //SC:O(1)
int pairSum(ListNode* head) {
        int cnt=0,n=0;
        
        ListNode *prev,*cur,*nt,*r;
        cur=head;
        while(cur!=NULL)
        {
            n++;
            cur=cur->next;
        }
        prev=head;
        while(cnt!=n/2)
        {
            prev=prev->next;
            cnt++;
        }
        cur=prev->next;
        if(cur!=NULL)
            nt=cur->next;
        while(cur!=NULL)
        {
            cur->next=prev;
            prev=cur;
            cur=nt;
            if(cur!=NULL)
                nt=cur->next;
        }
        cur=prev;
        r=cur;
        prev=head;
        cnt=0;
        int ans=0;
        while(cnt!=n/2)
        {
            ans=max(ans,(prev->val)+(cur->val));
            prev=prev->next;
            cur=cur->next;
            cnt++;
        }
        prev=NULL;
        cur=r;
        if(cur)
            nt=cur->next;
        cnt=0;
        while(cnt!=n/2)
        {
            cur->next=prev;
            prev=cur;
            cur=nt;
            if(cur)
                nt=cur->next;
            cnt++;
        }
        return ans;
    }