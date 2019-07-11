#
# @lc app=leetcode.cn id=783 lang=python3
#
# [783] 二叉搜索树结点最小距离
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    mindiff = 999999999
    last = -1

    def minDiffInBST(self, root: TreeNode) -> int:
        self.mind(root)
        return self.mindiff

    def mind(self, root):
        if root == None:
            return
        self.mind(root.left)
        if self.last == -1:
            self.last = root.val
        else:
            self.mindiff = min(self.mindiff, root.val-self.last)
            self.last = root.val
        self.mind(root.right)
