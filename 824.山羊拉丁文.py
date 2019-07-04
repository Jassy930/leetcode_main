#
# @lc app=leetcode.cn id=824 lang=python3
#
# [824] 山羊拉丁文
#
class Solution:
    def toGoatLatin(self, S: str) -> str:
        yuan = ('a','e','i','o','u','A','E','I','O','U')
        se = S.split(' ')
        for i in range(len(se)):
            if se[i][0] in yuan:
                se[i]=se[i]+'ma'
            else:
                se[i]=se[i][1:]+se[i][0]+'ma'
            se[i]+='a'*(i+1)
        return ' '.join(se)


