class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        if not n%2 == 0:
            n = (n-1)/2
            while n >= 1:
                if not n%2 == 0:
                    return False
                else:
                    n = n/2
                if n%2 == 0:
                    return False
                n = n/2
                
        else:
            n = n/2
            while n >= 1:
                if n%2 == 0:
                    return False
                else:
                    n = (n-1)/2
                if not n%2 == 0:
                    return False
                n = n/2
        
        return True
                
