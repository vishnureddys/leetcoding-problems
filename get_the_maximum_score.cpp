// https://leetcode.com/problems/get-the-maximum-score/

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long int dp1 = 0;
        long long int dp2 = 0;
        int i = 0;int j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                dp1 +=nums1[i];
                i++;               
            }
            else if(nums2[j]<nums1[i]){
                dp2 +=nums2[j];
                j++;
            }
            else{
                dp1 = dp2 = max(dp1 + nums1[i],dp2+nums1[i]);
                i++;
                j++;
            }
        }
         while(i<nums1.size())
             dp1 +=nums1[i++];
         while(j<nums2.size())
             dp2+=nums2[j++];
        
        return max(dp1,dp2)%1000000007;       
        
        
    }
};