#
# @lc app=leetcode.cn id=830 lang=python3
#
# [830] 较大分组的位置
#
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        ans=[[0]]
        ou = []
        for i in range(len(S)-1):
            if S[i] != S[i+1]:
                ans[-1].append(i)
                ans.append([i+1])
        ans[-1].append(len(S)-1)
        for i in ans:
            if i[1]-i[0] >=2:
                ou.append(i)
        return ou

