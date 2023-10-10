//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

//Level Order:
//TC:O(n)   //SC:O(n)
queue<TreeNode*> q;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root)
            q.push(root);
        while(!q.empty())
        {
            TreeNode* f=q.front();
            if(f)
            {
                q.push(f->left);
                q.push(f->right);
                ans.append(to_string(f->val)+",");
            }
            else
                ans.append("N,");
            q.pop();            
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;
        int i=0,j=i;
        while(data[j]!=',')
            j++;
        string str=data.substr(i,j-i);
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* f=q.front();
            if(!f)
            {
                q.pop();
                continue;
            }
            i=j+1;
            j=i;
            while(data[j]!=',')
                j++;
            string l=data.substr(i,j-i);
            i=j+1;
            j=i;
            while(data[j]!=',')
                j++;
            string r=data.substr(i,j-i);
            
            if(l!="N")
                f->left=new TreeNode(stoi(l));
            else
                f->left=NULL;
            q.push(f->left);
            if(r!="N")
                f->right=new TreeNode(stoi(r));
            else
                f->right=NULL;
            q.push(f->right);
            q.pop();
        }
        return root;
    }

//PreOrder:
//TC:O(n)   //SC:O(n)
void preorder(TreeNode* root,string &ans)
    {
        if(!root)
        {
            ans.append("N,");
            return;
        }
        ans.append(to_string(root->val)+",");
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* fun(queue<TreeNode*> &q)
    {
        TreeNode* root=q.front();
        q.pop();
        if(!root)
            return root;
        root->left=fun(q);
        root->right=fun(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i=0,j=i,n=data.size();
        queue<TreeNode*> q;
        if(!n)
            return NULL;
        TreeNode* root=NULL;
        while(j<n)
        {
            while(data[j]!=',')
                j++;
            string str=data.substr(i,j-i);
            if(str!="N")
                root=new TreeNode(stoi(str));
            else
                root=NULL;
            q.push(root);
            i=j+1;
            j=i;
        }

        return fun(q);
    }

//PostOrder:
//TC:O(n)   //SC:O(n)
void postorder(TreeNode* root,string &ans)
    {
        if(!root)
        {
            ans.append("N,");
            return;
        }
        
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.append(to_string(root->val)+",");
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        postorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* fun(deque<TreeNode*> &q)
    {
        TreeNode* root=q.back();
        q.pop_back();
        if(!root)
            return root;     
        root->right=fun(q);
        root->left=fun(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i=0,j=i,n=data.size();
        deque<TreeNode*> q;
        if(!n)
            return NULL;
        TreeNode* root=NULL;
        while(j<n)
        {
            while(data[j]!=',')
                j++;
            string str=data.substr(i,j-i);
            if(str!="N")
                root=new TreeNode(stoi(str));
            else
                root=NULL;
            q.push_back(root);
            i=j+1;
            j=i;
        }

        return fun(q);
    }