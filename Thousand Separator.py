class Solution(object):
    def thousandSeparator(self, n):
        """
        :type n: int
        :rtype: str
        """
        n = list(str(n))
        l = len(n)
        for i in range(3, l, 3):
            n.insert(l-i, ".")
        return "".join(n)
