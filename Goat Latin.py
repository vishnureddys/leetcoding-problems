class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        
        
        vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        Slist = S.split(" ")
        for i in range(len(Slist)):
            wlist = list(Slist[i])
            if not wlist[0] in vowels:
                wlist.append(wlist[0])
                wlist.pop(0)
            wlist.append("maa"+"a"*i)
            Slist[i] = "".join(wlist)
        return " ".join(Slist)
