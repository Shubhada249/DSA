//https://leetcode.com/problems/search-a-2d-matrix/

//TC:O(log(mn))     //SC:O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target==matrix[mid][n-1])
                return true;
            else if(target>matrix[mid][n-1])
                low=mid+1;
            else
                high=mid-1;
        }
        if(low>=m)
            return false;
        int r=low;
        low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(target==matrix[r][mid])
                return true;
            else if(target>matrix[r][mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }