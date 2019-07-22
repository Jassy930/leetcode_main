#
# @lc app=leetcode.cn id=383 lang=python3
#
# [383] 赎金信
#
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        rr = {}
        mm = {}
        for i in ransomNote:
            rr[i] = rr.get(i,0)+1
        for i in magazine:
            mm[i] = mm.get(i,0)+1
        for c,num in rr.items():
            if num > mm.get(c,0):
                return False
        return True
