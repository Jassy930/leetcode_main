#
# @lc app=leetcode.cn id=724 lang=python3
#
# [724] 寻找数组的中心索引
#


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return -1
        elif len(nums) == 1:
            return 0
        left = 0
        right = sum(nums)-nums[0]
        for i in range(len(nums)):
            if left == right:
                return i
            left += nums[i]
            if i+1<len(nums):
                right -= nums[i+1]
        return -1
