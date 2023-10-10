//https://leetcode.com/problems/binary-tree-right-side-view/

//TC:O(n)   //SC:O(n)
vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int val;
            while(sz--)
            {
                TreeNode* temp=q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                val=temp->val;
                q.pop();
            }
            ans.push_back(val);
        }
        return ans;
           
    }