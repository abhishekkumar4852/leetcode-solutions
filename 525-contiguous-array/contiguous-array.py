class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        zeros = 0
        ones = 0
        max_len = 0
        diff_map = {0:-1}

        for i in range(len(nums)):
            if nums[i] == 0:
                zeros +=1
            else:
                ones +=1

            diff = zeros - ones

            if diff in diff_map:
                max_len = max(max_len , i - diff_map[diff])
            else:
                diff_map[diff] = i

        return max_len
        