class Solution:
    def findMaximizedCapital(self, numProjects: int, initialCapital: int, profits: List[int], capital: List[int]) -> int:
        projectIndex = 0
        totalProjects = len(profits)

        # Create a list of tuples where each tuple consists of (capital required, profit)
        projects = list(zip(capital, profits))

        # Sort the projects based on the capital required in ascending order
        projects.sort()

        # Use a max heap to keep track of the maximum profits available within the current capital
        maxProfitHeap = []

        # Iterate through the number of projects we can undertake
        for currentProject in range(numProjects):
            # Push all projects that can be started with the current capital into the max heap
            while projectIndex < totalProjects and projects[projectIndex][0] <= initialCapital:
                heapq.heappush(maxProfitHeap, -projects[projectIndex][1])
                projectIndex += 1

            # If no projects can be started, return the current capital
            if not maxProfitHeap:
                return initialCapital

            # Add the profit of the project with the maximum profit to the current capital
            initialCapital -= heapq.heappop(maxProfitHeap)

        # Return the maximized capital after undertaking up to k projects
        return initialCapital
             
        
        