/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode-cn.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (59.38%)
 * Total Accepted:    4.6K
 * Total Submissions: 7.8K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 * 
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 * 
 * 
 * 
 * 示例 :
 * 
 * 输入:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * 输出: 16
 * 
 * 解释: 它的周长是下面图片中的 16 个黄色的边：
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid.at(0).size();

        int landcount = 0;
        int lincount = 0;

        for(int i=0; i<m; i++)
        {
            for(int k=0; k<n; k++)
            {
                if(grid.at(i).at(k) == 1)
                {
                    landcount++;
                    lincount+=countlin(grid, i, k, m, n);
                }
            }
        }
        return 4*landcount - lincount;

    }

    int countlin(vector<vector<int>> &grid, int i, int k, int m, int n)
    {
        int count = 0;
        if(i-1>=0 && grid.at(i-1).at(k) == 1) count++;
        if(i+1<m && grid.at(i+1).at(k) == 1) count++;
        if(k-1>=0 && grid.at(i).at(k-1) == 1) count++;
        if(k+1<n && grid.at(i).at(k+1) == 1) count++;
        return count;
    }
};
