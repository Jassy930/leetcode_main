#
# @lc app=leetcode.cn id=367 lang=python3
#
# [367] 有效的完全平方数
#
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num<0:
            return False
        x,i=0,1
        while x<num:
            x+=i
            i+=2
        return x==num


