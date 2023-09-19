class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = [0]* (n+1)
        
        for num in nums:
            if cnt[num] == 0:
                cnt[num] += 1
            else:
                return num
            
        return -1
        