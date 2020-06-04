class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key= lambda x: abs(x[0] - x[1]), reverse = True)
        #The sorting is done.
        n = len(costs)/2
        i = 0
        a = 0
        b = 0
        cost = 0
        while( i < 2*n):
            if(costs[i][0]<costs[i][1] and a < n or b == n):
                a+=1
                cost += costs[i][0]
                i+=1
            else:
                cost += costs[i][1]
                b+=1
                i+=1
        return cost
