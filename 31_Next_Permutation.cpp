class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1])
                pos = i-1;
        }
        
        if(pos == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        
        int minNum = INT_MAX;
        int idx;
        
        for(int i = pos+1; i < n; i++){
            if(nums[i] > nums[pos]){
                if(minNum > nums[i]){
                    idx = i;
                    minNum = nums[i];
                }
            }
        }
        
        swap(nums[pos], nums[idx]);
        
        sort(nums.begin() + pos + 1, nums.end());
    }
};
