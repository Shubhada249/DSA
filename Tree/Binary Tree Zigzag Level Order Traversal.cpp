//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//TC:O(n)   //SC:O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ch=true;
        while(!q.empty())
        {
            int v=q.size();
            vector<int> temp(v);
            int i;
            if(ch)
                i=0;
            else
                i=v-1;
            while(v--)
            {
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
                if(ch)
                {
                    temp[i++]=q.front()->val;
                }
                else
                {
                    temp[i--]=q.front()->val;
                }
                q.pop();
            }
            if(ch)
                ch=false;
            else
                ch=true;
            ans.push_back(temp);
        }
        return ans;
    }