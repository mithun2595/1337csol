class Solution(object):

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result, visited = set(),{}
        for i in xrange(len(nums)-2):
            table, sum = {}, -nums[i]
            if nums[i] not in visited:
                for j in xrange(i+1, len(nums)):
                    if nums[j] not in table: table[sum - nums[j]] = j
                    else: result.add((nums[i], sum-nums[j], nums[j]))
                visited[nums[i]] = 1
        return list(result)