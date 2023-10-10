//https://practice.geeksforgeeks.org/problems/floor-in-bst/1

//TC:o(n)   //SC:O(1)
int floor(Node* root, int x) {
    // Code here
    int ans=-1;
    while(root)
    {
        if(x==root->data)
            return x;
        if(x<root->data)
            root=root->left;
        else
        {
            ans=root->data;
            root=root->right;
        }
    }
    return ans;
}