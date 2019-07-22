#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ans = True
    def isBalanced(self, root: TreeNode) -> bool:
        self.geth(root)
        return self.ans

    def geth(self, root):
        if root == None:
            return
        self.geth(root.left)
        self.geth(root.right)
        if root.left == None and root.right == None:
            root.height = 1
        elif root.left == None:
            root.height = root.right.height+1
            if root.height > 2:
                self.ans = False
                return False
        elif root.right == None:
            root.height = root.left.height+1
            if root.height > 2:
                self.ans = False
                return False
        else:
            root.height = max(root.left.height,root.right.height)+1
            if (abs(root.left.height-root.right.height) > 1):
                self.ans = False
                return False

