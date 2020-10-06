//https://leetcode.com/problems/count-and-say

class Solution {
public:
    string nextTerm(string str) {
        string ans = "";
        int init = str[0] - '0', count = 1;
        for(int i = 1; i < str.size(); ++i) {
            if(str[i] == str[i-1]) {
                count++;
                continue;
            } else {
                ans += to_string(count);
                ans += to_string(init);
                count = 1;
                init = str[i] - '0';
            }
        }
        ans += to_string(count);
        ans += to_string(init);
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; ++i) {
            ans = nextTerm(ans);
        }
        return ans;
    }
};
