/* Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n). */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it=nums.begin();
        it=unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        if(nums.size()<3)
            return nums[nums.size()-1];
        
        
        int ans= nums[nums.size()-(3)];
        return ans;
            
    }
};