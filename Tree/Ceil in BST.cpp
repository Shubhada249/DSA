//https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

//TC:O(n)   //SC:O(1)
int findCeil(Node* root, int input) {
    int ans=-1;
    while(root)
    {
        if(root->data==input)
            return input;
        else if(input<root->data)
        {
            ans=root->data;
            root=root->left;
        }
        else
            root=root->right;
    }
    return ans;
}