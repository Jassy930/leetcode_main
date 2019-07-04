#
# @lc app=leetcode.cn id=917 lang=python3
#
# [917] 仅仅反转字母
#
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        ou=[]
        for i in S:
            if (i>='a' and i<='z') or (i>='A' and i<='Z'):
                ou.append(i)
        ou = ou[-1::-1]
        for i in range(len(S)):
            if not((S[i]>='a' and S[i]<='z') or (S[i]>='A' and S[i]<='Z')):
                ou.insert(i,S[i])
        return ''.join(ou)

