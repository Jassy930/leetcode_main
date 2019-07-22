#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#
class Solution:
    def reverseVowels(self, s: str) -> str:
        a=[x for x in s if x in 'aeiouAEIOU']
        a=a[::-1]
        ss=list(s)
        for i in range(len(ss)):
            if ss[i] in 'aeiouAEIOU':
                ss[i] = a[0]
                a=a[1:]
        return ''.join(ss)
        

