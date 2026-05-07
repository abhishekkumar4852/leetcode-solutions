class Solution:
    def intervalIntersection(self,firstList : List[List[int]],secondList : List[List[int]])-> List[List[int]] :
        i: int = 0
        j : int= 0
        result : List[List[int]]= []

        while i < len(firstList) and j < len(secondList):
            start: int = max(firstList[i][0] , secondList[j][0])
            end: int = min (firstList[i][1] , secondList[j][1])

            if start <= end :
                result.append([start,end])

            if firstList[i][1] < secondList[j][1]:
                i +=1
            else:
                j+=1

        return result