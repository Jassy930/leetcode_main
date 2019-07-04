#
# @lc app=leetcode.cn id=1078 lang=python3
#
# [1078] Bigram 分词
#
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        tt = text.split(' ')
        ou = []
        for i in range(0,len(tt)-2):
            if tt[i] == first and tt[i+1] == second:
                ou.append(tt[i+2])
        return ou
        

