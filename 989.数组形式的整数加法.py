#
# @lc app=leetcode.cn id=989 lang=python3
#
# [989] 数组形式的整数加法
#
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        aa = 0
        for i in range(len(A)):
            aa*=10
            aa+=A[i]
        o=[]
        b=aa+K
        if b == 0:
            return [0]
        while b!=0:
            o.insert(0,b%10)
            b=b//10
        return o

