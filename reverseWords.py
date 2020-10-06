# https://leetcode.com/problems/reverse-words-in-a-string/

class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        res = ""
        for i in arr:
            if(len(i)>0 and len(res)>0):
                res = i+" "+res
            elif(len(res)==0):
                res = i
        return res