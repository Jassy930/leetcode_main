#
# @lc app=leetcode.cn id=796 lang=python3
#
# [796] 旋转字符串
#
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        for i in range(len(A)+1):
            if A == B:
                return True
            A = A[1:]+A[0]
        return False

