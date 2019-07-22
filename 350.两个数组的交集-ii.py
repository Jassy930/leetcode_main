#
# @lc app=leetcode.cn id=350 lang=python3
#
# [350] 两个数组的交集 II
#
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        dd = {}
        for i in nums1:
            dd[i] = dd.get(i,0)+1
        for i in nums2:
            if dd.get(i,0) > 0:
                dd[i]-=1
                ans.append(i)
        return ans

