#
# @lc app=leetcode.cn id=941 lang=python3
#
# [941] 有效的山脉数组
#
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A)<3:
            return False
        i=0
        if A[i]>=A[i+1]:
            return False
        while i<len(A)-1:
            if A[i]<A[i+1]:
                i+=1
            else:
                break
        if i>=len(A)-1:
            return False
        while i<len(A)-1:
            if A[i]>A[i+1]:
                i+=1
            else:
                break
        if i>=len(A)-1:
            return True
        else:
            return False

