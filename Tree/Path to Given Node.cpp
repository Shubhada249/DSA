//https://www.interviewbit.com/problems/path-to-given-node/

//TC:O(n)   //SC:O(n)
bool fun(TreeNode* A, int B,vector<int> &ans)
{
    if(!A)
        return false;
    if(A->val==B)
    {
        ans.push_back(A->val);
        return true;
    }
    bool ch=fun(A->left,B,ans) || fun(A->right,B,ans);
    if(ch)
        ans.push_back(A->val);
    return ch;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool ch=fun(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
