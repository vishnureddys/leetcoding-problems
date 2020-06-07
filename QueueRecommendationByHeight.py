class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        newlist = []
        people.sort(key=lambda x: (x[0]*-1 , x[1]))
        print(people)
        for i,j in people:
            newlist.insert(j,[i,j])
        return newlist
