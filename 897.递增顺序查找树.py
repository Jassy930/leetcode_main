#
# @lc app=leetcode.cn id=897 lang=python3
#
# [897] 递增顺序查找树
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    r = TreeNode(0)
    def increasingBST(self, root):
        tree=self.r
        self.ins(root)
        return tree.right

    def ins(self, root):
        if root == None:
            return
        self.ins(root.left)
        self.r.right = TreeNode(root.val)
        self.r = self.r.right
        self.ins(root.right)
