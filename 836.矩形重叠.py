#
# @lc app=leetcode.cn id=836 lang=python3
#
# [836] 矩形重叠
#
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        if rec2[0]>=rec1[2] or rec2[2]<=rec1[0]:
            return False
        if rec2[1]>=rec1[3] or rec2[3]<=rec1[1]:
            return False
        return True
        

