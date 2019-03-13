/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 不同的子序列 II
 *
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.67%)
 * Total Accepted:    6.5K
 * Total Submissions: 8.9K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A 已按非递减顺序排序。
 * 
 * 
 */
class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> out;
        if (A.size() == 0)
            return out;
        else if (A.size() == 1)
        {
            out.push_back(A.at(0) * A.at(0));
            return out;
        }
        else if (A.back()<=0)
        {
            for(int i=A.size()-1; i>=0; i--){
                out.push_back(A.at(i)*A.at(i));
            }
            return out;
        }
        else if(A.front()>=0)
        {
            for(int i=0; i<A.size(); i++)
            {
                out.push_back(A.at(i)*A.at(i));
            }
            return out;
        }
        int m, n;
        m = 0;
        n = 0;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A.at(i) <= 0 && A.at(i + 1) > 0)
            {
                m = i;
                break;
            }
        }
        n=m+1;

        while (m >= 0 || n < A.size())
        {
            // cout<<m<<" "<<n<<endl;
            if (m < 0)
            {
                out.push_back(A.at(n) * A.at(n));
                n++;
            }
            else if (n >= A.size())
            {
                out.push_back(A.at(m) * A.at(m));
                m--;
            }
            else if (abs(A.at(m)) < abs(A.at(n)))
            {
                out.push_back(A.at(m) * A.at(m));
                m--;
            }
            else
            {
                out.push_back(A.at(n) * A.at(n));
                n++;
            }
        }
        return out;
    }
};
