class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        res = []
        greatest = max(candies)
        for p in candies:
            if p+extraCandies < greatest:
                res.append(False)
            else:
                res.append(True)
                
        return res
