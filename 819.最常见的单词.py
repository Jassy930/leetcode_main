#
# @lc app=leetcode.cn id=819 lang=python3
#
# [819] 最常见的单词
#
class Solution:
    def mostCommonWord(self, paragraph: str, banned) -> str:
        paragraph = re.sub('[^a-zA-Z]',' ',paragraph)
        words = [ x.lower() for x in paragraph.split(' ')]
        ww = {}
        banned.append('')
        maxcount=0
        maxword=""
        for w in words:
            if w in ww:
                ww[w] += 1
            else:
                ww[w] = 1
        for i in banned:
            if i in ww:
                ww[i] = 0
        for i,k in ww.items():
            if k > maxcount:
                maxcount = k
                maxword = i
        return maxword

