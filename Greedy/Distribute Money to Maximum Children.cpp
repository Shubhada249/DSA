//https://leetcode.com/problems/distribute-money-to-maximum-children/

//TC:O(children)    //SC:O(1)
int distMoney(int money, int children) {       
        if(money<children)  return -1;  //check second condition
        money-=children;                //1 dollar allocated to Everyone
        int cnt=children;
        while(money-7>=0 && cnt>1){        
            money-=7;
            cnt--;
        }      
        int ans=children-cnt;
        if(cnt!=1) return ans;
        if(money==3) ans--;
        else if(money==7) ans++;
        return ans;
    }