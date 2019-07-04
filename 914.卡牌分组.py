#
# @lc app=leetcode.cn id=914 lang=python3
#
# [914] 卡牌分组
#
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        num={}
        for i in deck:
            if i in num:
                num[i]+=1
            else:
                num[i]=1
        k=-1
        for i in num.values():
            if k==-1:
                k=i
            k=self.hcf(k,i)
        if k>1:
            return True
        else:
            return False

    def hcf(self, a, b):
        if a<b:
            a,b=b,a
        while a%b!=0:
            c=a%b
            a=b
            b=c
        return b

