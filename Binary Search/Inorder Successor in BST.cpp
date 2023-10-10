//https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//TC:O(height of tree)  //SC:O(1)
Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node *ans=NULL,*cur=root;;
        while(cur)
        {
            if(x->data < cur->data)
            {
                ans=cur;
                cur=cur->left;
            }
            else
                cur=cur->right;
        }
        
    }