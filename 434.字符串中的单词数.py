#
# @lc app=leetcode.cn id=434 lang=python3
#
# [434] 字符串中的单词数
#
class Solution:
    def countSegments(self, s: str) -> int:
        ss = s.split(' ')
        return len(ss)-ss.count('')

