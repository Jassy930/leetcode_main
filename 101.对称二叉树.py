#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        rows=[[root]]
        queue=[root]
        while len(queue)!=0:
            newq = []
            while len(queue)!=0:
                if queue[0]!=None:
                    newq.append(queue[0].left)
                    newq.append(queue[0].right)
                queue = queue[1:]
            for i in range(len(newq)):
                if newq[i]!=None and newq[-1*i-1] and newq[i].val != newq[-1*i-1].val:
                    return False
                if newq[i] == None and newq[-1-i] != None:
                    return False
                if newq[i] != None and newq[-1-i] == None:
                    return False
            queue = newq
        return True
        

