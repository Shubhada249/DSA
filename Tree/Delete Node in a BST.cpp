//https://leetcode.com/problems/delete-node-in-a-bst/

//TC:O(height of tree)   //SC:O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        TreeNode *lt,*rt,*ln,*prev,*cur;        
        if(key==root->val)
        {
            lt=root->left;
            rt=root->right;
            if(!lt)
                return rt;
            ln=lt;
            while(ln->right)
                ln=ln->right;
            ln->right=rt;
            return lt;
        }
        prev=root;
        cur=root;
        while(cur && cur->val!=key)
        {
            prev=cur;
            if(key<cur->val)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if(!cur)
            return root;
        lt=cur->left;
        rt=cur->right;
        ln=lt;
        while(ln && ln->right)
            ln=ln->right;
        if(lt)
            ln->right=rt;
        if(key<prev->val)
        {
            if(lt)
                prev->left=lt;
            else
                prev->left=rt;
        }
        else
        {
            if(lt)
                prev->right=lt;
            else
                prev->right=rt;
        }
        return root;
    }