#
# @lc app=leetcode.cn id=290 lang=python3
#
# [290] 单词规律
#
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        ss = str.split(' ')
        if len(pattern)!= len(ss):
            return False
        dd = {}
        for i,c in enumerate(pattern):
            if c in dd:
                if dd[c]!=ss[i]:
                    return False
            else:
                dd[c] = ss[i]
        if len(set([x for x in pattern])) != len(set(ss)):
            return False
        return True

