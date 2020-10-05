// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur = INT_MIN;
        vector<int> a(nums.size(),0);
        vector<int> b(nums.size(),0);
        a[0] = nums[0];
        b[0] = nums[0];
        int ma = a[0];
        for(int i = 1 ;i<nums.size();i++){
            if(nums[i]<0){
                a[i] = max(nums[i],b[i-1]*nums[i]);
                b[i] = min(nums[i],a[i-1]*nums[i]);
            }
            else{
                a[i] = max(nums[i],a[i-1]*nums[i]);
                b[i] = min(nums[i],b[i-1]*nums[i]);
            }
            ma = max(a[i],ma);
            
        }
        return ma;
    }
};