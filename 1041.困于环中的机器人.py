#
# @lc app=leetcode.cn id=1041 lang=python3
#
# [1041] 困于环中的机器人
#
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        pos=[0,0]
        move = [[0,1],[-1,0],[0,-1],[1,0]]
        cm = 0

        for k in range(100):
            for i in instructions:
                if i == 'G':
                    pos[0]+=move[cm][0]
                    pos[1]+=move[cm][1]
                if i == 'L':
                    cm+=1
                if i == 'R':
                    cm-=1
                if cm>3:
                    cm-=4
                if cm<0:
                    cm+=4
            if pos[0] == 0 and pos[1] == 0 and cm == 0:
                return True

        return False


