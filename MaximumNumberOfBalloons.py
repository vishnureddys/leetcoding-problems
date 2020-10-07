class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        text = list(text)
        
        out = 0
        letters = {'b' : 1, 'a' : 1, 'l' : 2, 'o' : 2, 'n' : 1} 
        contains = 1
        
        while contains:
            for letter in letters.keys():
                count = text.count(letter)
                if count < letters[letter]:
                    contains = 0
                    break
                else:
                    for _ in range(letters[letter]):
                        text.remove(letter)
            if contains:
                out += 1
            
        return out
