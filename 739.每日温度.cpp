/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (58.21%)
 * Total Accepted:    3.7K
 * Total Submissions: 6.4K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
 * 
 */
class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> out(T.size());
        stack<pair<int, int>> ss;

        ss.push({T.at(0), 0});
        for (int i = 1; i < T.size(); i++)
        {
            if (ss.top().first > T.at(i))
            {
                ss.push({T.at(i), i});
                continue;
            }

            while (!ss.empty() && ss.top().first < T.at(i))
            {
                out.at(ss.top().second) = i - ss.top().second;
                ss.pop();
            }
            ss.push({T.at(i), i});
        }
        return out;
    }
};
