//https://leetcode.com/problems/symmetric-tree/

Recursive:
//TC:O(n)   //SC:O(n)
bool fun(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 || !root2)
        {
            return root1==root2;
        }
        return (fun(root1->left,root2->right) && fun(root1->right,root2->left) && root1->val == root2->val);
    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }

Iterative:

Level order
//TC:O(n)   //SC:O(n)
bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1,q2;
        if(root->left && root->right && root->left->val==root->right->val)
        {
            q1.push(root->left);
            q2.push(root->right);
        }
        else if(!root->left && !root->right){}            
        else
            return false;
            
        while(!q1.empty() && !q2.empty())
        {
            if(q1.front()->left && q2.front()->right && q1.front()->left->val==q2.front()->right->val)
            {
                q1.push(q1.front()->left);
                q2.push(q2.front()->right);
            }
            else if(!q1.front()->left && !q2.front()->right){}              
            else
                return false;
            if(q1.front()->right && q2.front()->left && q1.front()->right->val==q2.front()->left->val)
            {
                q1.push(q1.front()->right);
                q2.push(q2.front()->left);
            }
            else if(!q1.front()->right && !q2.front()->left){}                
            else
                return false;
            q1.pop();
            q2.pop();            
        }
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }

Inorder/Preorder/Postorder
//TC:O(n)   //SC:O(n)
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        TreeNode *cur1=NULL,*cur2=NULL;
        if(root->left && root->right && root->left->val==root->right->val)
        {
            cur1=root->left;
            cur2=root->right;
        }
        else if(!root->left && !root->right){}                    
        else
            return false;
        
        while(true)//
        {
            if(!((!cur1 && !cur2)||(cur1 && cur2 && cur1->val==cur2->val)))
                return false;
            if(cur1)
            {
                s1.push(cur1);
                cur1=cur1->left;
            }
            else
            {
                if(s1.empty())
                    break;
                cur1=s1.top()->right;
                s1.pop();
            }
            
            if(cur2)
            {
                s2.push(cur2);
                cur2=cur2->right;
            }
            else
            {
                if(s2.empty())
                    break;
                cur2=s2.top()->left;
                s2.pop();
            }
        }
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }