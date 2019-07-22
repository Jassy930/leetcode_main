#
# @lc app=leetcode.cn id=733 lang=python3
#
# [733] 图像渲染
#
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        flag = [[0]*n for x in range(m)]
        queue = [[sr,sc]]
        while len(queue)!=0:
            if queue[0][0]+1<m and image[queue[0][0]+1][queue[0][1]] == image[queue[0][0]][queue[0][1]] and flag[queue[0][0]+1][queue[0][1]] == 0:
                queue.append([queue[0][0]+1,queue[0][1]])
                flag[queue[0][0]+1][queue[0][1]]=1
            if queue[0][1]+1<n and image[queue[0][0]][queue[0][1]+1] == image[queue[0][0]][queue[0][1]] and flag[queue[0][0]][queue[0][1]+1] == 0:
                queue.append([queue[0][0],queue[0][1]+1])
                flag[queue[0][0]][queue[0][1]+1]=1
            if queue[0][0]-1>=0 and image[queue[0][0]-1][queue[0][1]] == image[queue[0][0]][queue[0][1]] and flag[queue[0][0]-1][queue[0][1]] == 0:
                queue.append([queue[0][0]-1,queue[0][1]])
                flag[queue[0][0]-1][queue[0][1]]=1
            if queue[0][1]-1>=0 and image[queue[0][0]][queue[0][1]-1] == image[queue[0][0]][queue[0][1]] and flag[queue[0][0]][queue[0][1]-1] == 0:
                queue.append([queue[0][0],queue[0][1]-1])
                flag[queue[0][0]][queue[0][1]-1]=1
            image[queue[0][0]][queue[0][1]] = newColor
            queue=queue[1:]
        return image

