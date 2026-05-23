class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        low = matrix[0][0]
        high = matrix[n-1][n-1]

        while low < high:
            mid = (low + high) // 2
            count = 0
            rows = n-1
            cols = 0

            while rows>= 0 and cols < n:
                if matrix[rows][cols]<= mid:
                    count += rows+1
                    cols +=1
                else:
                    rows -= 1

            if count < k:
               low = mid +1

            else:
                high = mid 

        return low


        