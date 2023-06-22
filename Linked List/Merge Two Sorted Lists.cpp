//https://leetcode.com/problems/merge-two-sorted-lists/

//TC:O(m+n)     //SC:O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        ListNode *prev,*head;
        if(list2->val < list1->val)
        {
            head=list2;
            prev=list2;
            list2=list2->next;
        }
        else
        {
            head=list1;
            prev=list1;
            list1=list1->next;
        }
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                prev->next=list1;
                prev=list1;
                list1=list1->next;              
            }
            else
            {
                prev->next=list2;
                prev=list2;
                list2=list2->next;        
            }
        }
        if(list1!=NULL)
        {
            prev->next=list1;
        }
        if(list2!=NULL)
        {
            prev->next=list2;
        }
        return head;
    }