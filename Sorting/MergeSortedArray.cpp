//https://leetcode.com/problems/merge-sorted-array/

//TC:O(m+n)     //SC:O(m+n)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(nums2[j]);
            j++;
        }
        nums1=ans;
    }

//TC:O(m+n)     //SC:O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
        while(i>=0 && i!=k)
        {
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }