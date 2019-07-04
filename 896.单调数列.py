#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        count=0
        for i in range(len(A)-1):
            if A[i]>A[i+1]:
                count+=1
        if count == 0:
            return True
        count=0
        for i in range(len(A)-1):
            if A[i]<A[i+1]:
                count+=1
        if count == 0:
            return True
        return False

