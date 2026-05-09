class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0]*n
        stack = []

        for i, temp in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                 index = stack.pop()
                 ans[index] = i - index
            stack.append(i)


        return ans



        