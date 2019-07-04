#
# @lc app=leetcode.cn id=997 lang=python3
#
# [997] 找到小镇的法官
#
class Solution:
    # def findJudge(self, N: int, trust: List[List[int]]) -> int:
    def findJudge(self, N: int, trust) -> int:
        trusted=[[] for x in range(N)]
        trus =[[] for x in range(N)]
        for tr in trust:
            trusted[tr[1]-1].append(tr[0]-1)
            trus[tr[0]-1].append(tr[1]-1)
        for i in range(N):
            if len(trusted[i]) == N-1 and len(trus[i]) == 0:
                return i+1
        return -1

