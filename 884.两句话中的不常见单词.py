#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        words={}
        ref = []
        for x in (A+' '+B).split(' '):
            if x in words:
                words[x]+=1
            else:
                words[x]=1
        for x,y in words.items():
            if y==1:
                ref.append(x)
        return ref

