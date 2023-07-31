//https://leetcode.com/problems/delete-node-in-a-linked-list/

//TC:O(1)   //SC:O(1)
void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }