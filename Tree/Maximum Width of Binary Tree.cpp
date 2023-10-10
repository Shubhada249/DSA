//https://leetcode.com/problems/maximum-width-of-binary-tree/
//TC:O(n)   //SC:O(n)
int widthOfBinaryTree(TreeNode* root) {
        int ans=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int sz=q.size();
            int start=q.front().second;
            int end;
            while(sz--)
            {
                if(sz==0)
                    end=q.front().second;
                TreeNode *f=q.front().first;
                long long ind=q.front().second;
                if(f->left)
                    q.push({f->left,2*(ind-start)+1});
                if(f->right)
                    q.push({f->right,2*(ind-start)+2});
                q.pop();
            }
            ans=max(ans,end-start+1);           
        }
        return ans;
    }