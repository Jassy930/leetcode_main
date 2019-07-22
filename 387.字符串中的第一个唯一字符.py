#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i,c in enumerate(s):
            if c not in s[:i]+s[i+1:]:
                return i
        return -1

