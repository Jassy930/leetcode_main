#
# @lc app=leetcode.cn id=859 lang=python3
#
# [859] 亲密字符串
#
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        aa=""
        bb=""
        if len(A)!=len(B):
            return False
        for i in range(len(A)):
            if A[i]!=B[i]:
                aa+=A[i]
                bb+=B[i]

        if len(aa)==2:
            if aa == bb[-1::-1]:
                return True
            else:
                return False
        elif len(aa) == 0:
            aaa=set()
            for i in A:
                aaa.add(i)
            if len(aaa) !=len(A):
                return True
            else:
                return False
        else:
            return False

