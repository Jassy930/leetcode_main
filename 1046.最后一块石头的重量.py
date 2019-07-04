#
# @lc app=leetcode.cn id=1046 lang=python3
#
# [1046] 最后一块石头的重量
#


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 1:
            return stones[0]
        elif len(stones) == 0:
            return 0
        for i in range(len(stones)-1):
            if stones[i] > stones[i+1]:
                stones[i], stones[i+1] = stones[i+1], stones[i]
        for i in range(len(stones)-1):
            if stones[i] > stones[i+1]:
                stones[i], stones[i+1] = stones[i+1], stones[i]
        if stones[-1] == stones[-2]:
            stones = stones[:-2]
            return self.lastStoneWeight(stones)
        else:
            stones[-2] = stones[-1] - stones[-2]
            stones = stones[:-1]
            return self.lastStoneWeight(stones)
