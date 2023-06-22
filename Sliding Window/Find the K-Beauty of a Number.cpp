//https://leetcode.com/problems/find-the-k-beauty-of-a-number/

//TC:O(n)   //SC:O(n)
int divisorSubstrings(int num, int k) {
    int i=0,j=0;
    string strnum=to_string(num);
    int n=strnum.size(),ans=0;
    
    string str="";
    while(j<n)
    {
        str.push_back(strnum[j]);
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            if(stoi(str)!=0 && num%stoi(str)==0)
                ans++;
            str.erase(0,1);
            i++;
            j++;
        }
    }
    return ans;
}