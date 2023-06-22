//https://leetcode.com/problems/minimum-moves-to-reach-target-score/

//TC:O(log n)   //SC:O(1)
int minMoves(int target, int maxDoubles) {
        int steps=0;
        while(target!=1 && maxDoubles)
        {
            if(((target & 1)==0) && maxDoubles)
            {
                target=target>>1;
                maxDoubles--;
            }
            else
            {
                target--;
            }
            steps++;
        }
        if(target==1)
            return steps;
        else
            return steps+target-1;
        return steps;
    }