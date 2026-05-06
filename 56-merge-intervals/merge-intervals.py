class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()

        merged = []

        for interval in  intervals:
            if not merged:
              merged.append(interval)

            else :

               last = merged[-1]

               if last[1] < interval [0]:
                  merged.append(interval)
               else:
                  last[1] = max(last[1], interval[1])

        return merged



        