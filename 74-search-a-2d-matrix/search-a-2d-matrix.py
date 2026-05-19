class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False

        row = len(matrix)
        cols = len(matrix[0])
        r = 0
        c = cols - 1

        while r < row and c>= 0:
            if matrix [r][c] == target:
                return True

            elif matrix [r] [c] > target:
                c -=1

            else:
                r +=1

        return False

        