#
# @lc app=leetcode.cn id=874 lang=python3
#
# [874] 模拟行走机器人
#
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        pos=[0,0]
        move = [[0,1],[-1,0],[0,-1],[1,0]]
        cm = 0
        maxdis = 0
        ob = set(map(tuple, obstacles))

        for i in commands:
            if i > 0 and i < 10:
                for m in range(i):
                    if (pos[0]+move[cm][0],pos[1]+move[cm][1]) not in ob:
                        pos[0]+=move[cm][0]
                        pos[1]+=move[cm][1]
                        maxdis = max(maxdis, pos[0]**2 + pos[1]**2)
            if i == -2:
                cm+=1
            if i == -1:
                cm-=1
            if cm>3:
                cm-=4
            if cm<0:
                cm+=4

        return maxdis

