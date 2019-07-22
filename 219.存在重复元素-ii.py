#
# @lc app=leetcode.cn id=219 lang=python3
#
# [219] 存在重复元素 II
#
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        num = {}
        for i,n in enumerate(nums):
            if n not in num:
                num[n] = [i]
            else:
                if i-num[n][-1] <= k:
                    return True
                else:
                    num[n] = [i]
        return False

