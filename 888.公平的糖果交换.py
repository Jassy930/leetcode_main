#
# @lc app=leetcode.cn id=888 lang=python3
#
# [888] 公平的糖果交换
#
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        diff = (sum(A)-sum(B))/2
        aa = {x:None for x in A}
        bb = {x:None for x in B}
        for i in A:
            if i-diff in bb:
                return [i,i-diff]
            # for k in B[-1::-1]:
            #     if i-k == diff:
            #         return [i,k]

