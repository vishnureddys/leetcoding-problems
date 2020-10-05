//Permutation Sequence leetcode #60

#include<bits/stdc++.h>

using namespace std;

    int factorial(int n)
    {
        return (n==1 || n==0) ? 1 : n * factorial(n - 1);  
    }
    
    string getPermutation(int n, int k) 
    {
        vector<int> digits;
        for(int i=1; i<=n; i++)
        {
            digits.push_back(i);
        }
        int index = 0;
        string ans="";
        vector<int> fact(n+1) ;
        fact[0]=-1;
        for(int i=1; i<=n; i++)
        {
            fact[i]=factorial(i);
        }
        while(n>0)
        {
            if(n==1)
            {
                index=0;
                ans += to_string(digits[index]);
            }
            else
            {
                index = k/fact[n-1];
                if(k%fact[n-1]==0)
                    index-=1;
                ans += to_string(digits[index]);
                digits.erase(digits.begin()+index);
                k = k - fact[n-1]*index;
            }
            n--;
        }
        return ans;
    }

    int main()
    {
        int n, k;
        cout<<"Enter n: ";
        cin>>n;
        cout<<"Enter k: ";
        cin>>k;
        string ans = getPermutation(n,k);
        cout<<"The answer is: \""<<ans<<"\"";
        return 0;
    }
