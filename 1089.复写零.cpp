/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> qq;
        for(int i=0; i<arr.size(); i++)
        {
            qq.push(arr[i]);
            if (arr[i] == 0) qq.push(0);
            arr[i] = qq.front();
            qq.pop();
        }
    }
};

