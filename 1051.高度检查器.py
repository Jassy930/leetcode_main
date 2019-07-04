#
# @lc app=leetcode.cn id=1051 lang=python3
#
# [1051] 高度检查器
#
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        hh = heights[:]
        hh.sort()
        count = 0
        for i in range(len(hh)):
            if hh[i]!=heights[i]:
                count+=1
        return count
        

