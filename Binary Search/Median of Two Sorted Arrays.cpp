//https://leetcode.com/problems/median-of-two-sorted-arrays/

//TC:O(m+n)     //SC:O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int t1=(m+n)/2,t2=t1+1,cnt=1,i=0,j=0,a,b;
        bool ch=false;
        while(i<m && j<n && ch==false)
        {
            if(cnt==t1)
                a=min(nums1[i],nums2[j]);
            else if(cnt==t2)
            {
                b=min(nums1[i],nums2[j]);
                ch=true;
            }
            if(nums1[i]<nums2[j])
                i++;
            else
                j++;           
            cnt++;
        }
        while(i<m && ch==false)
        {
            if(cnt==t1)
                a=(nums1[i]);
            else if(cnt==t2)
            {
                b=(nums1[i]);
                ch=true;
            }
            i++;          
            cnt++;
        }
        while(j<n && ch==false)
        {
            if(cnt==t1)
                a=(nums2[j]);
            else if(cnt==t2)
            {
                b=(nums2[j]);
                ch=true;
            }
            j++;          
            cnt++;
        }
        double ans;
        if((m+n)%2==0)
            ans=(a+b)/2.0;
        else
            ans=b;
            
        return ans;
    }

//TC:O(log(min(m,n)))       //SC:O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {            
        int m=nums1.size(),n=nums2.size(),part1=(m+n+1)/2;
        //int low=max(0,(m-n+1)/2),high=min(m,part1);  //This part is or for three lines after this line
        if(m>n)
            return findMedianSortedArrays(nums2,nums1);
        int low=0,high=m;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int cut1=mid,cut2=part1-mid;
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int r1=(cut1>=m)?INT_MAX:nums1[cut1];
            int r2=(cut2>=n)?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((m+n)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }