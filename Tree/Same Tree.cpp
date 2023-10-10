//https://leetcode.com/problems/same-tree/

//TC:O(n)   //SC:O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && !q))
            return true;
        if((!p && q)||(p && !q))
        {
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && (p->val == q->val);
    } 