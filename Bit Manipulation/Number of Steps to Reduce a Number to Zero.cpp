//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

//TC:O(32)      //SC:O(1)
int numberOfSteps(int num) {
        if(num==0)
            return 0;
        int noOfSetBits=0,noOfSteps=0;
        while(num!=0)
        {
            if((num&1)==1)
                noOfSetBits++;
            num=num>>1;
            noOfSteps++;
        }
        
        return noOfSetBits+noOfSteps-1;
    }