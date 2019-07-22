#
# @lc app=leetcode.cn id=720 lang=python3
#
# [720] 词典中最长的单词
#
class Solution:
    def longestWord(self, words: List[str]) -> str:
        ans=[]
        maxlength=0
        for word in words:
            if len(word) < maxlength:
                continue
            n=0
            for i in range(1,len(word)):
                if word[:i] not in words:
                    n+=1
                    break
            if n==0:
                if len(word) > maxlength:
                    maxlength=len(word)
                    ans=[word]
                elif len(word) == maxlength:
                    ans.append(word)
        ans.sort()
        return ans[0]


