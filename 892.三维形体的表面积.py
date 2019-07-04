#
# @lc app=leetcode.cn id=892 lang=python3
#
# [892] 三维形体的表面积
#
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        count=0
        for i in grid:
            for k in i:
                if k>0:
                    count+=2
                    count+=4*k
        for i in range(len(grid)-1):
            for k in range(len(grid[i])-1):
                count-=min(grid[i][k],grid[i+1][k])*2
                count-=min(grid[i][k],grid[i][k+1])*2
        for i in range(len(grid)-1):
            count-=min(grid[i][-1],grid[i+1][-1])*2
        for i in range(len(grid[0])-1):
            count-=min(grid[-1][i],grid[-1][i+1])*2
        return count
        

