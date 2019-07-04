#
# @lc app=leetcode.cn id=1047 lang=python3
#
# [1047] 删除字符串中的所有相邻重复项
#
class Solution:
    def removeDuplicates(self, S: str) -> str:
        i=0
        count = 0
        while i<len(S)-1:
            if S[i] == S[i+1]:
                S = S[:i]+S[i+2:]
                count+=1
            else:
                i+=1
        if count!=0:
            return self.removeDuplicates(S)
        else:
            return S

