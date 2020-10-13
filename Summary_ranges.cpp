/* Leetcode Problem : #228
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b
 */
 class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i<nums.size();i++)
        {
            int start = nums[i];
            int end = start;
            if(!(nums.size()==i+1))
            while(nums[i+1]-1==nums[i])
            {
                i++;
                end = nums[i];
                if(i==nums.size()-1)
                    break;
            }
            if(start==end)
            {
                ans.push_back(to_string(start));
            }
            else
                ans.push_back(to_string(start)+"->"+to_string(end));
        }
        return ans;
    }
};