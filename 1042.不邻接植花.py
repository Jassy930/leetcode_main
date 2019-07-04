#
# @lc app=leetcode.cn id=1042 lang=python3
#
# [1042] 不邻接植花
#
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        roads = [[] for x in range(N)]
        flower = [0]*N
        for path in paths:
            roads[path[0]-1].append(path[1])
            roads[path[1]-1].append(path[0])
        flower[0] = 1
        queue = roads[0][:]
        i=0

        while i<N:
            while len(queue)!=0:
                j=queue[0]
                exist= []
                for garden in roads[j-1]:
                    if flower[garden-1] !=0 and (flower[garden-1] not in exist):
                        exist.append(flower[garden-1])
                for k in range(1,5):
                    if k not in exist:
                        flower[j-1] = k
                        break
                queue = queue[1:]
            while i<N and flower[i]!=0:
                i+=1
            queue = [i+1]
        return flower

