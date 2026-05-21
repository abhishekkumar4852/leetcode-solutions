from collections import Counter
class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)

        if max(count.values())> (len(s)+1)//2:
           return ""
        
        ans = [""]*len(s)
        i = 0 
        for ch,freq in count.most_common():
            while freq > 0:
                ans[i]= ch
                i +=2

                if i >= len(s):
                    i =1

                freq -=1

        return "".join(ans)
        