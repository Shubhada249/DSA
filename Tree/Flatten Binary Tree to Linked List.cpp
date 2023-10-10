//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

//Recursion + not in place
//TC:O(n)   //SC:o(2n)
void preorder(TreeNode* root,TreeNode* &prev)
    {
        if(!root)
            return;
        if(prev!=root)
        {
           prev->right=new TreeNode(root->val);
            prev->left=NULL;
            prev=prev->right;
        }
        TreeNode *rt=root->right;
        preorder(root->left,prev);
        preorder(rt,prev);
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=root;
        preorder(root,prev);
    }

//Recursion +  in place
//TC:O(n)   //SC:o(n)
void fun(TreeNode* root,TreeNode* &ln)
    {
        if(!root)
            return;
        TreeNode *rt=root->right;
        if(root->left)
            fun(root->left,ln);
        else
            ln=root;
        if(root->left)
            root->right=root->left;
        root->left=NULL;
        ln->right=rt;
        fun(rt,ln);
    }
    void flatten(TreeNode* root) {
        TreeNode *ln=NULL;
        fun(root,ln);
    }

//Interative +  in place
//TC:O(n)   //SC:o(1)
void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur)
        {
            if(!cur->left)
                cur=cur->right;
            else if(!cur->right)
            {
                cur->right=cur->left;
                cur->left=NULL;
                cur=cur->right;
            }
            else
            {
                TreeNode* lnols=cur->left;
                while(lnols->left || lnols->right)
                {
                    if(lnols->right)
                        lnols=lnols->right;
                    else
                        lnols=lnols->left;
                }
                lnols->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
                cur=cur->right;
            }
        }
    }