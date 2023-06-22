//https://leetcode.com/problems/linked-list-cycle/

//TC:O(n)   //SC:O(n)   //n is no. of nodes in list
bool hasCycle(ListNode *head) {
        unordered_map<ListNode *,int> mp;
        while(head!=NULL)
        {
            mp[head]++;
            if(mp[head]>1)
                return true;
            head=head->next;
        }
        return false;
    }

//TC:O(n)   //SC:O(1)   //n is no. of nodes in list
bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *fast=head->next,*slow=head;
        while(fast!=slow && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==slow)
            return true;
        else
            return false;
    }