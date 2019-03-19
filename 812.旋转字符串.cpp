/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 旋转字符串
 *
 * https://leetcode-cn.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (55.20%)
 * Total Accepted:    2K
 * Total Submissions: 3.5K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 
 * 
 * 示例:
 * 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * 输出: 2
 * 解释: 
 * 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
 * 
 * 
 * 
 * 
 * 注意: 
 * 
 * 
 * 3 <= points.length <= 50.
 * 不存在重复的点。
 * -50 <= points[i][j] <= 50.
 * 结果误差值在 10^-6 以内都认为是正确答案。
 * 
 * 
 */
class Solution
{
  public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double out = 0;
        for (int i = 0; i < points.size() - 2; i++)
        {
            for (int j = i + 1; j < points.size() - 1; j++)
            {
                for (int k = j + 1; k < points.size(); k++)
                {
                    out = max(out, abs((double)(points.at(i).at(0) * points.at(j).at(1) + points.at(j).at(0) * points.at(k).at(1) + points.at(k).at(0) * points.at(i).at(1) - points.at(i).at(0) * points.at(k).at(1) - points.at(j).at(0) * points.at(i).at(1) - points.at(k).at(0) * points.at(j).at(1))));
                }
            }
        }
        return out / 2;
    }
};
