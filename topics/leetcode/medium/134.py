class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        diffs = [(gas[i] - cost[i], i) for i in range(len(gas))]
        diffs = sorted(diffs, reverse=True)

        # now we know the order to start from,
        start = diffs[0][1] # get the value from the tuple 
        total = 0
        for i in range(len(gas)):
            revenue = gas[(i + start) % len(gas)] - cost[(i + start) % len(gas)]
            print(i, " revenue is ", revenue, " index is ", (i + start) % len(gas))
            total += revenue
            if total < 0:
                return -1
        return start 


# testing
if __name__ == "__main__":
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]

    s = Solution()
    print(s.canCompleteCircuit(gas, cost)) # expect 3