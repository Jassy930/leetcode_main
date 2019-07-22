#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        while head!=None and head.val == val:
            head = head.next
        root = head
        while head!=None and head.next!=None:
            if head.next.val == val:
                head.next = head.next.next
            else:
                head = head.next
        return root

