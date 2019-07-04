#
# @lc app=leetcode.cn id=784 lang=python3
#
# [784] 字母大小写全排列
#
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        S = S.lower()
        letter = [x for x,y in enumerate(S) if y.isalpha()]
        ans=[]
        for i in range(2**len(letter)):
            ll = [x for x in S]
            for m,n in enumerate(letter):
                if (i//(2**(m))) %2 == 1:
                    ll[n] = ll[n].upper()
            ans.append(''.join(ll))
        return ans

        

