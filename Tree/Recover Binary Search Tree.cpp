//https://leetcode.com/problems/recover-binary-search-tree/

//TC:O(n)   //SC:O(1)
void recoverTree(TreeNode* root) {
        TreeNode *cur=root,*prev=NULL,*f,*s,*rmnolst;
        bool ch=false;
        while(cur)
        {
            if(!cur->left)
            {
                if(prev!=NULL && prev->val>cur->val)
                {
                    if(ch)
                        s=cur;
                    else
                    {
                        f=prev;
                        s=cur;
                        ch=true;
                    }
                }
                prev=cur;
                cur=cur->right;
                continue;
            }
            rmnolst=cur->left;
            while(rmnolst->right!=NULL && rmnolst->right!=cur)
                rmnolst=rmnolst->right;
            if(rmnolst->right==cur)
            {
                if(prev!=NULL && prev->val>cur->val)
                {
                    if(ch)
                        s=cur;
                    else
                    {
                        f=prev;
                        s=cur;
                        ch=true;
                    }
                }
                prev=cur;
                rmnolst->right=NULL;
                cur=cur->right;
            }
            else
            {
                rmnolst->right=cur;
                cur=cur->left;
            }
        }
        swap(f->val,s->val);
        
    }