//https://leetcode.com/problems/linked-list-cycle-ii/

//TC:O(n)   //SC:O(n)
ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,int> mp;
        while(head!=NULL)
        {
            mp[head]++;
            if(mp[head]>1)
                return head;
            head=head->next;
        }
        return NULL;
    }

//TC:O(n)   //SC:O(1)
ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *slow=head,*fast=head->next;
        while(slow!=fast && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast)
        {
            slow=slow->next;
            fast=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }