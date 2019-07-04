#
# @lc app=leetcode.cn id=953 lang=python3
#
# [953] 验证外星语词典
#
class Solution:
    cost={}
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        for i in range(len(order)):
            self.cost[order[i]] = i
        for i in range(len(words)-1):
            if not self.smallthan(words[i], words[i+1]):
                return False
        return True
    def smallthan(self, wda, wdb):
        i=0
        while i<len(wda) and i <len(wdb):
            if self.cost[wda[i]] < self.cost[wdb[i]]:
                return True
            elif self.cost[wda[i]] > self.cost[wdb[i]]:
                return False
            i+=1
        return len(wda)<len(wdb)
        

