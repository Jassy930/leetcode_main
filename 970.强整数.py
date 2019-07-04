#
# @lc app=leetcode.cn id=970 lang=python3
#
# [970] 强整数
#
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        ou=[]
        i=0
        while x**i<bound:
            k=0
            c = y**k+x**i
            while c<=bound:
                if c not in ou:
                    ou.append(c)
                k+=1
                c = y**k+x**i
                if y == 1:
                    break
            i+=1
            if x==1:
                break
        return ou
                

