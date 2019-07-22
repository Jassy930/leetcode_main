#
# @lc app=leetcode.cn id=686 lang=python3
#
# [686] 重复叠加字符串匹配
#
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        S = A
        ans = 1
        while len(S) < 2*len(A)+len(B):
            if B in S:
                return ans
            S = S + A
            ans += 1
        return -1

