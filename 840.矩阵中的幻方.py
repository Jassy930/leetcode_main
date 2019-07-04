#
# @lc app=leetcode.cn id=840 lang=python3
#
# [840] 矩阵中的幻方
#


class Solution:
    def numMagicSquaresInside(self, grid) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        for i in range(m-2):
            for k in range(n-2):
                sum=0
                sum+=(grid[i][k]+grid[i+1][k]+grid[i+2][k])%15
                sum+=(grid[i][k+1]+grid[i+1][k+1]+grid[i+2][k+1])%15
                sum+=(grid[i][k+2]+grid[i+1][k+2]+grid[i+2][k+2])%15
                sum+=(grid[i][k]+grid[i][k+1]+grid[i][k+2])%15
                sum+=(grid[i+1][k]+grid[i+1][k+1]+grid[i+1][k+2])%15
                sum+=(grid[i+2][k]+grid[i+2][k+1]+grid[i+2][k+2])%15
                sum+=(grid[i][k]+grid[i+1][k+1]+grid[i+2][k+2])%15
                sum+=(grid[i+2][k]+grid[i+1][k+1]+grid[i][k+2])%15
                if sum == 0:
                    nn = list(set([x for y in grid[i:i+3] for x in y[k:k+3]]))
                    nn.sort()
                    if len(nn) == 9 and nn[0]==1 and nn[-1] == 9:
                        res+=1
        return res

