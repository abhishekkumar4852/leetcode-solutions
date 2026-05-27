class Solution:
    def isPalindrome(self, x: int,left:int = None,right:int = None) -> bool:
      
        
        if left is None  and  x < 0:
            return False

        s = str(x)

        if left is None and right is None:
            left = 0
            right = len(s) - 1

        if left >= right:
            return True

        if s[left] != s[right]:
            return False
        return self.isPalindrome(x,left+1,right-1)
          

        