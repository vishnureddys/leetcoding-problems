class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxfar = INT_MIN, max_near = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            max_near = max(nums[i],nums[i]+max_near);
            maxfar = max(maxfar,max_near);
        }
        return maxfar;
    }
};