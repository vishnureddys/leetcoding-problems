// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
    
        if(x<0) return -1;
        if(x==0 || x==1) return x;
        
        int left=1;
        int right=x;
        long long int mid;
        long long int ans;
        while(left<=right){
           mid=left+(right-left)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid<x){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
