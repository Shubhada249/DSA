//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


//TC:O(n)   //SC:O(n)
void fun(Node *root,vector <int> &ans)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            ans.push_back(root->data);
            return;
        }
        fun(root->left,ans);
        fun(root->right,ans);
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        Node * prev;
        ans.push_back(root->data);
        if(!root->left && !root->right)
            return ans;
        if(root->left)
        {
            ans.push_back(root->left->data);
            prev=root->left;
        while(true)
        {
            if(prev->left)
            {
                ans.push_back(prev->left->data);
                prev=prev->left;
            }
            else if(prev->right)
            {
                ans.push_back(prev->right->data);
                prev=prev->right;
            }
            else
            {
                ans.pop_back();
                break;
            }
        }
        }
        fun(root,ans);
        int ind=ans.size();
        if(root->right)
        {
            ans.push_back(root->right->data);
            prev=root->right;
            while(true)
            {
                
                if(prev->right)
                {
                    ans.push_back(prev->right->data);
                    prev=prev->right;
                }
                else if(prev->left)
                {
                    ans.push_back(prev->left->data);
                    prev=prev->left;
                }
                else
                {
                    ans.pop_back();
                    break;
                }
            }
            
            reverse(ans.begin()+ind,ans.end());
        }
        return ans;
    }