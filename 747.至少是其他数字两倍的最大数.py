#
# @lc app=leetcode.cn id=747 lang=python3
#
# [747] 至少是其他数字两倍的最大数
#
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        ans = 0
        maxnum = -11111111
        maxnum2 = -11111111111
        for i in range(len(nums)):
            if nums[i]>maxnum:
                maxnum2 = maxnum
                maxnum = nums[i]
                ans = i
            elif nums[i]>maxnum2:
                maxnum2 = nums[i]
        if maxnum >= 2*maxnum2:
            return ans
        else:
            return -1


