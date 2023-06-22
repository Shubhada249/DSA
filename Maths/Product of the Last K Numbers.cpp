//https://leetcode.com/problems/product-of-the-last-k-numbers/

//SC:O(n)
class ProductOfNumbers {
public:
    vector<int> vec;
    int li=-1;
    ProductOfNumbers() {
        
    }
    //TC:O(1)
    void add(int num) {
        int n=vec.size();
        if(num==0)
        {
            li=n;
            vec.push_back(1);
        }
        else
        {
            if(vec.size()==0)
                vec.push_back(num);
            else
                vec.push_back(vec[n-1]*num);
        }
    }
    //TC:O(1)
    int getProduct(int k) {
        int n=vec.size();
        if(li>=n-k)
            return 0; 
        if(n-k-1>=0)
            return vec[n-1]/vec[n-k-1];
        return vec[n-1];
    }
};
