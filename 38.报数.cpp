/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.00%)
 * Total Accepted:    21K
 * Total Submissions: 43.7K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 6.     312211   13112221    1113213211
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        vector<vector<int>> countArr;
        vector<int> vv(1,1);
        countArr.push_back(vv);
        while(countArr.size() < n)
        {
            vector<int> vvv;
            int num = countArr.back().at(0);
            int count = 0;
            for(int i = 0; i< countArr.back().size(); i++)
            {
                if(count == 0) {num = countArr.back().at(i); count++;}
                else if(num == countArr.back().at(i)) count++;
                else {
                    vvv.push_back(count);
                    vvv.push_back(num);
                    count = 1;
                    num = countArr.back().at(i);
                }
            }
            vvv.push_back(count);
            vvv.push_back(num);
            countArr.push_back(vvv);
        }
        stringstream ss;
        for(int i=0; i<countArr.back().size(); i++)
        {
            ss<<countArr.back().at(i);
        }
        return ss.str();
    }
};

