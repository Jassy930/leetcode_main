/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 戳印序列
 *
 * https://leetcode-cn.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (64.99%)
 * Total Accepted:    2.4K
 * Total Submissions: 3.8K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
 * 
 * （这里，平面上两点之间的距离是欧几里德距离。）
 * 
 * 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,3],[-2,2]], K = 1
 * 输出：[[-2,2]]
 * 解释： 
 * (1, 3) 和原点之间的距离为 sqrt(10)，
 * (-2, 2) 和原点之间的距离为 sqrt(8)，
 * 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
 * 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
 * 输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
 * 
 * 
 * [[3,3],[5,-1],[-2,4]]\n2
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 * 
 * 18 26 20
 */
class Solution
{
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        if(points.size() == 0) return vector<vector<int>>{};
        vector<int> distance;
        for (int i = 0; i < points.size(); i++)
        {
            distance.push_back(points.at(i).at(0) * points.at(i).at(0) + points.at(i).at(1) * points.at(i).at(1));
        }
        multimap <int,int> mindismap;
        vector<vector<int>> out;
        for (int i = 0; i < points.size(); i++)
        {
            mindismap.insert({distance.at(i),i});
        }
        multimap <int,int>::iterator ii=mindismap.begin();
        for (int i=0; i<K; i++)
        {
            out.push_back(points.at(ii->second));
            ii++;
        }
        return out;
    }
};
