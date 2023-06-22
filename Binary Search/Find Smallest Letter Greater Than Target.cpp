//
//https://leetcode.com/problems/find-smallest-letter-greater-than-target/

//TC:O(log n)   //SC:O(1)
char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size(),low=0,high=n-1;
        char ans=letters[0];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(letters[mid]>target)
            {
                ans=letters[mid];
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }