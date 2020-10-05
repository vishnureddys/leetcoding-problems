// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        vector<int> vec;
        while(x>0){
            vec.push_back(x%10);
            x = x/10;
        }
        vector<int> rev = vec;
        int n = vec.size();
        reverse(rev.begin(), rev.end());
        for(int i=0;i<n;i++){
            if(rev[i]!=vec[i]) return false;
        }
        return true;
    }
};