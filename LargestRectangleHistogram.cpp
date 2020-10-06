// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> A = heights;
        int n = A.size();
        if(n==0) return 0;
        int right[100000];
        int left[100000];
        for(int i=0;i<n;++i){
            right[i] = n;
            left[i] = -1;
        }
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;++i){
            if(A[s.top()]<A[i]){
                left[i] = s.top();
            }
            else{
                while(!s.empty() && A[s.top()]>=A[i]){
                    right[s.top()] = i;
                    s.pop();
                }
                if(!s.empty()) left[i] = s.top();
            }
            s.push(i);
        }
        long long int area[100000];
        for(int i=0;i<n;++i) area[i] = (right[i]-left[i]-1)*A[i];
        return *max_element(area,area+n);
        }
};
