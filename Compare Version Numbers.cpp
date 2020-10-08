//https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        long long num1=0,num2=0;
        for(long long i=0,j=0;(i<version1.length()|| j<version2.length());)
        {
            while(i<version1.length() && version1[i]!='.')
            {
                num1=num1*10 + (version1[i]-'0');
                i++;
            }
            while(j<version2.length() && version2[j]!='.')
            {
                num2=num2*10 +(version2[j]-'0');
                j++;
            }
            if(num1>num2) return 1;
            else if(num1<num2) return -1;
            else
            {
                num1=num2=0;
                i++;
                j++;
            }
        }
        return 0;
    }
};
