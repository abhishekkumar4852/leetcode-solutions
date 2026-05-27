class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def backtract(index, path):
            if index == len(nums):
                result.append(path[:])
                return

            path.append(nums[index])
            backtract(index + 1 , path)

            path.pop()

            backtract(index + 1 , path)

        backtract(0, [])
        return result
        