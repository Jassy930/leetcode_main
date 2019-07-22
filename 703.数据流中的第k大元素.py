#
# @lc app=leetcode.cn id=703 lang=python3
#
# [703] 数据流中的第K大元素
#


class KthLargest:
    # min heap
    k = 0
    heap = []
    maxvalue = 0

    def __init__(self, k: int, nums):
        self.k = k
        self.heap = [-999990]*k
        for i in nums:
            self.ad(i)

    def add(self, val: int) -> int:
        self.ad(val)
        return self.heap[0]

    def ad(self, val):
        if val < self.heap[0]:
            return
        self.heap[0] = val
        k = 0
        k1 = 1
        k2 = 2
        while k1 < self.k:
            if k2 >= self.k:
                if self.heap[k] > self.heap[k1]:
                    self.heap[k], self.heap[k1] = self.heap[k1], self.heap[k]
                    k = k1
                break
            if self.heap[k] < self.heap[k1] and self.heap[k] < self.heap[k2]:
                break
            if self.heap[k1] > self.heap[k2]:
                self.heap[k], self.heap[k2] = self.heap[k2], self.heap[k]
                k = k2
            else:
                self.heap[k], self.heap[k1] = self.heap[k1], self.heap[k]
                k = k1
            k1 = 2*k+1
            k2 = 2*k+2
            # Your KthLargest object will be instantiated and called as such:
            # obj = KthLargest(k, nums)
            # param_1 = obj.add(val)
