class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        fuck ={}

        for ch in magazine:
            fuck[ch] = fuck.get(ch,0)+1
        for ch in ransomNote:
            if ch not in fuck or fuck[ch] == 0:
                return False

            fuck[ch] -=1
        return True

            

        
        
        