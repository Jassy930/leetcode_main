#
# @lc app=leetcode.cn id=925 lang=python3
#
# [925] 长按键入
#
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        na=[name[0]]
        nb=[1]
        sa=[typed[0]]
        sb=[1]
        for i in range(1,len(name)):
            if name[i] == na[-1]:
                nb[-1]+=1
            else:
                na.append(name[i])
                nb.append(1)
        for i in range(1,len(typed)):
            if typed[i] == sa[-1]:
                sb[-1]+=1
            else:
                sa.append(typed[i])
                sb.append(1)
        if len(na)!= len(sa):
            return False
        for i in range(len(na)):
            if na[i] != sa[i]:
                return False
            if nb[i] > sb[i]:
                return False
        return True
        

