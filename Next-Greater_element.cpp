//https://leetcode.com/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i = 0;
        if(nums.size() == 0)return nums;
        stack<pair<int , int>> s;
        s.push(make_pair(nums[0] , 0));
        int n = nums.size();
        
        vector <int> vis(n , 0);
        vector<int> b(n , 0);
        for(int i = 0 ; i < 2*n ; i++){
            while(!s.empty() && s.top().first < nums[i%n]){
                b[s.top().second] = nums[i%n];
                s.pop();
            }
            if(vis[i%n] != 1){
                s.push(make_pair(nums[i%n] , i%n));
                vis[i%n] = 1;
            }
        }
        while(!s.empty()){
            b[s.top().second] = -1;
            s.pop();
        }
        return b;
    }
};