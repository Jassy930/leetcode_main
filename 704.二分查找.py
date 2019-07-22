#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return {x:i for i,x in enumerate(nums)}.get(target,-1)

