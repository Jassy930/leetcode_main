#
# @lc app=leetcode.cn id=748 lang=python3
#
# [748] 最短完整词
#


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        ll = ''.join([x.lower() for x in licensePlate if x.isalpha()])
        ans = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        for word in words:
            if len(word)>=len(ans):
                continue
            ww = word[:]
            for letter in ll:
                if letter in ww:
                    ww = ww[:ww.find(letter)]+ww[ww.find(letter)+1:]
                else:
                    break
            if len(word) - len(ww) == len(ll) and len(word)<len(ans):
                ans = word
        return ans
