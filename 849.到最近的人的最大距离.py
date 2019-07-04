#
# @lc app=leetcode.cn id=849 lang=python3
#
# [849] 到最近的人的最大距离
#
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        pos=[]
        maxdis=0
        maxpos = 0
        for i in range(len(seats)):
            if seats[i] == 1:
                pos.append(i)
        if pos[0] > maxdis:
            maxdis = pos[0]
            maxpos = 0
        if len(seats) - pos[-1] - 1 > maxdis:
            maxdis = len(seats)-pos[-1]-1
            maxpos = len(seats)-1
        for i in range(len(pos)-1):
            if (pos[i+1]-pos[i])//2 > maxdis:
                maxdis = (pos[i+1]-pos[i])//2
                maxpos = (pos[i+1]+pos[i])//2
        return maxdis
