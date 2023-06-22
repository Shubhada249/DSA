//https://leetcode.com/problems/move-zeroes/

//TC:O(n^2)//SC:O(1)
void moveZeroes(vector<int>& nums) {        //Bubble Sort Approach
        int n=nums.size(),j;
        for(int i=0;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(nums[j]==0 && nums[j+1]!=0)
                    swap(nums[j],nums[j+1]);
            }
            if(nums[j]!=0)
                break;
        }       
    }


//TC:O(2n)//SC:O(1)
void moveZeroes(vector<int>& nums) {
        int n=nums.size(),i=0,j=0;
        while(i<n)  //TC:O(n)
        {
            if(nums[i]==0)
                i++;
            else
            {
                if(i!=j)
                {
                    nums[j]=nums[i];
                }
                i++;
                j++;
            }
        }
        while(j<n)  //TC:O(n)
        {
            nums[j]=0;
            j++;
        }
    }

//TC:O(n)//SC:O(1)
void moveZeroes(vector<int>& nums) {    //small extension of above approach
        int n=nums.size(),i=0,j=0;
        while(i<n)
        {
            if(nums[i]==0)
                i++;
            else
            {
                if(i!=j)
                {
                    swap(nums[j],nums[i]);
                }
                i++;
                j++;
            }
        }
    }