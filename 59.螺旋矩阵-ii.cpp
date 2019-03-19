/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (71.23%)
 * Total Accepted:    6.9K
 * Total Submissions: 9.7K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        int sig = 0;
        vector<int> o(n);
        vector<vector<int>> out(n, o);
        int p = 0, q = 0;
        for (int i = 1; i <= n * n; i++)
        {
            out.at(p).at(q) = i;

            if (sig == 0)
            {
                if (q + 1 < n && out.at(p).at(q + 1) == 0)
                    q++;
                else
                {
                    sig++;
                    p++;
                }
            }
            else if (sig == 1)
            {
                if (p + 1 < n && out.at(p + 1).at(q) == 0)
                    p++;
                else
                {
                    sig++;
                    q--;
                }
            }
            else if (sig == 2)
            {
                if (q - 1 >= 0 && out.at(p).at(q - 1) == 0)
                    q--;
                else
                {
                    sig++;
                    p--;
                }
            }
            else if (sig == 3)
            {
                if (p - 1 >= 0 && out.at(p - 1).at(q) == 0)
                    p--;
                else
                {
                    sig = 0;
                    q++;
                }
            }
            // cout << p << "," << q << "|";
        }
        return out;
    }
};
